/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
#include "usbdfu.h"
#include <string.h>

#define CM_RESET_VECTOR_OFFSET    4

static void jump_to_application(void) __attribute__ ((noreturn));

static void jump_to_application(void) {
  chSysLock();
  SysTick->CTRL &= ~0b11; // Disable & 
  /* Use the application's vector table */
  // Copy Vector Table to RAM_START(0x10000000)
  memcpy((void*) 0x10000000, (void*)APP_BASE, 256);
  // Switch Vector Table
  LPC_SYSCON->SYSMEMREMAP = 0x1; // User RAM mode
  __ASM volatile("dsb");

  /* Initialize the application's stack pointer */
  __set_MSP(*((volatile uint32_t*)(APP_BASE)));
  register uint32_t target_start = *((volatile uint32_t*)(APP_BASE + CM_RESET_VECTOR_OFFSET)) | 1;
  register uint32_t initial_sp = *((volatile uint32_t*)(APP_BASE));
  /* Jump to the application entry point */
  __ASM volatile ("mov sp, %0\n" "bx %1" : : "r" (initial_sp), "r" (target_start) : );

  while (1);
}

inline bool is_dfu_pressed(void) {
  #ifdef SNOWFOX_TST
    return !palReadLine(LINE_BTN1);
  #else
    palSetLine(LINE_ROW1);
    __NOP(); __NOP(); __NOP();
    return palReadLine(LINE_COL1);
  #endif
}

/*
 * Application entry point.
 */
int main(void) {
  halInit();
/*
 * System initializations.
 * - Kernel initialization, the main() function becomes a thread and the
 *   RTOS is active.
 */
  chSysInit();

  uint32_t checksum = 0x0;
  for (int i = 0; i < 8; ++i)
  {
    checksum += ((uint32_t*)APP_BASE)[i];
  }

  uint32_t magic = *((volatile uint32_t*) 0x100001F0);

  if (!is_dfu_pressed()) {
    if (checksum == 0 && *((volatile uint32_t*)APP_BASE) != 0xFFFFFFFF && *((volatile uint32_t*)APP_BASE) != 0 && magic != 0xDEADBEEF) {
      jump_to_application();
    }
  }

  *((volatile uint32_t*) 0x100001F0) = 0x0;

  usbDisconnectBus(&USBD1);
  chThdSleepMilliseconds(1500);
  usbStart(&USBD1, &usbcfg);
  usbConnectBus(&USBD1);

  while(1) {
    chThdSleepSeconds(600);
  }
}
