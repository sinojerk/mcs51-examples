    .globl _DELAY100MS
    
    .area CSEG    (CODE)
_DELAY100MS:   ; 12Mhz
    push    0x30
    push    0x31
    mov     0x30,#193
    mov     0x31,#125
DELAY100MSNEXT:
    djnz    0x31,DELAY100MSNEXT
    djnz    0x30,DELAY100MSNEXT
    pop     0x31
    pop     0x30
    ret
