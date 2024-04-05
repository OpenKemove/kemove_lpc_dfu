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
.weak 
