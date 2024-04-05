MEMORY {
    flash(rx) : ORIGIN = 0x00000000, LENGTH = 64k
    ram0(rw)  : ORIGIN = 0x10000000, LENGTH = 6k
}

ENTRY(Reset_Handler);

__main_stack_end__ = ORIGIN(sram) + LENGTH(sram);

SECTIONS {
  .vectors  : { KEEP(*(.vectors)) }   > flash
  .text     : { *(.text*) }           > flash
  .rodata   : { *(.rodata*) }         > flash

  .data : {
    _sdata = .;   /* .data section start */
    KEEP(*(.data .data.*))
    _edata = .;  /* .data section end */
  } > sram AT > flash
  _sidata = LOADADDR(.data);

  .bss : {
    __bss_base__ = .;              /* .bss section start */
    *(.bss SORT(.bss.*) COMMON)
    __bss_end__ = .;               /* .bss section end */
  } > sram

  . = ALIGN(8);
  _end = .;     /* for cmsis_gcc.h  */

  /DISCARD/ : {
    *(.init .fini)
    *(.ARM.attributes)
    *(.comment)
  }
}