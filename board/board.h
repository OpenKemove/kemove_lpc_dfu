#pragma once
/*
    ChibiOS - Copyright (C) 2006..2020 Giovanni Di Sirio

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

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for mTrain board.
 */

/*
 * Board identifier.
 */
#define BOARD_KEMOVE_SNOWFOX
#define BOARD_NAME                  "Kemove Snowfox"

#ifndef LPC11U35
#define LPC11U35
#endif

#if defined(SNOWFOX_V3)

#define LINE_LED                                        PAL_LINE(IOPORT0, 1)

#define LINE_USBCONN                                    PAL_LINE(IOPORT0, 6)
#define LINE_USBVBUS                                    PAL_LINE(IOPORT0, 3)

#define LINE_ROW1                                       PAL_LINE(IOPORT1, 25)
#define LINE_ROW2                                       PAL_LINE(IOPORT0, 20)
#define LINE_ROW3                                       PAL_LINE(IOPORT1, 4)
#define LINE_ROW4                                       PAL_LINE(IOPORT1, 20)
#define LINE_ROW5                                       PAL_LINE(IOPORT1, 24)
#define LINE_ROW6                                       PAL_LINE(IOPORT1, 19)
#define LINE_ROW7                                       PAL_LINE(IOPORT1, 17)
#define LINE_ROW8                                       PAL_LINE(IOPORT1, 23)

#define LINE_COL1                                       PAL_LINE(IOPORT1, 18)
#define LINE_COL2                                       PAL_LINE(IOPORT0, 7)
#define LINE_COL3                                       PAL_LINE(IOPORT1, 28)
#define LINE_COL4                                       PAL_LINE(IOPORT1, 5)
#define LINE_COL5                                       PAL_LINE(IOPORT1, 2)
#define LINE_COL6                                       PAL_LINE(IOPORT1, 8)
#define LINE_COL7                                       PAL_LINE(IOPORT0, 22)
#define LINE_COL8                                       PAL_LINE(IOPORT0, 11)
#define LINE_COL9                                       PAL_LINE(IOPORT1, 11)

#elif defined(SNOWFOX_V1_5)

#define LINE_LED                                        PAL_LINE(IOPORT0, 1)

#define LINE_USBCONN                                    PAL_LINE(IOPORT0, 6)
#define LINE_USBVBUS                                    PAL_LINE(IOPORT0, 3)

#define LINE_ROW1                                       PAL_LINE(IOPORT1, 25)
#define LINE_ROW2                                       PAL_LINE(IOPORT0, 0)
#define LINE_ROW3                                       PAL_LINE(IOPORT1, 20)
#define LINE_ROW4                                       PAL_LINE(IOPORT0, 5)
#define LINE_ROW5                                       PAL_LINE(IOPORT0, 7)
#define LINE_ROW6                                       PAL_LINE(IOPORT1, 19)
#define LINE_ROW7                                       PAL_LINE(IOPORT1, 23)
#define LINE_ROW8                                       PAL_LINE(IOPORT1, 24)

#define LINE_COL1                                       PAL_LINE(IOPORT1, 28)
#define LINE_COL2                                       PAL_LINE(IOPORT1, 31)
#define LINE_COL3                                       PAL_LINE(IOPORT0, 22)
#define LINE_COL4                                       PAL_LINE(IOPORT1, 29)
#define LINE_COL5                                       PAL_LINE(IOPORT0, 11) // Alt Setting
#define LINE_COL6                                       PAL_LINE(IOPORT0, 12) // Alt
#define LINE_COL7                                       PAL_LINE(IOPORT0, 13) // Alt
#define LINE_COL8                                       PAL_LINE(IOPORT0, 14) // Alt
#define LINE_COL9                                       PAL_LINE(IOPORT1, 13)

// LEDControllers
#define LINE_SSP1_MOSI                                  PAL_LINE(IOPORT0, 21)
#define LINE_SSP1_MISO                                  PAL_LINE(IOPORT1, 21)
#define LINE_SSP1_SCK                                   PAL_LINE(IOPORT1, 15)
#define LINE_LED1_CS                                    PAL_LINE(IOPORT1, 12)
#define LINE_LED2_CS                                    PAL_LINE(IOPORT0, 17)


#define LINE_UART_RX                                    PAL_LINE(IOPORT1, 14)
#define LINE_UART_TX                                    PAL_LINE(IOPORT1, 27)
#define LINE_BLE_RSTN                                   PAL_LINE(IOPORT0, 20)

#else // SNOWFOX_VER
#error "Unknown Board"
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
