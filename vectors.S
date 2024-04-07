.extern __main_stack_end__

.section .vectors, "ax"
.align 4
.globl _vectors

# 0
.long __main_stack_end__
.long Reset_Handler
.long NMI_Handler
.long HardFault_Handler
.long 0
.long 0
.long 0
.long 0
.long 0
.long 0
.long 0
.long SVC_Handler
.long DebugMon_Handler
.long Vector34
.long PendSV_Handler
.long SysTick_Handler
.long Vector40, Vector44, Vector48, Vector4C
.long Vector50, Vector54, Vector58, Vector5C
.long Vector60, Vector64, Vector68, Vector6C
.long Vector70, Vector74, Vector78, Vector7C
.long Vector80, Vector84, Vector88, Vector8C
.long Vector90, Vector94, Vector98, Vector9C
.long VectorA0, VectorA4, VectorA8, VectorAC
.long VectorB0, VectorB4, VectorB8, VectorBC


.text
.align 2
.thumb_func
.globl Reset_Handler
Reset_Handler:
_here:
    b _here

.thumb_func
.weak NMI_Handler
NMI_Handler:
    b NMI_Handler

.weak HardFault_Handler
HardFault_Handler:
    b HardFault_Handler

.weak SVC_Handler
SVC_Handler:
    b SVC_Handler

.weak DebugMon_Handler
DebugMon_Handler:
    b DebugMon_Handler

.weak Vector34
.weak PendSV_Handler
.weak SysTick_Handler
.weak Vector40
.weak Vector44
.weak Vector48
.weak Vector4C
.weak Vector50
.weak Vector54
.weak Vector58
.weak Vector5C
.weak Vector60
.weak Vector64
.weak Vector68
.weak Vector6C
.weak Vector70
.weak Vector74
.weak Vector78
.weak Vector7C
.weak Vector80
.weak Vector84
.weak Vector88
.weak Vector8C
.weak Vector90
.weak Vector94
.weak Vector98
.weak Vector9C
.weak VectorA0
.weak VectorA4
.weak VectorA8
.weak VectorAC
.weak VectorB0
.weak VectorB4
.weak VectorB8
.weak VectorBC
nop_handler:
    b nop_handler