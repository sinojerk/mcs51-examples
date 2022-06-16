#include "lint.h"

#include "STC89xx.h"
#include "delay.h"

#define LED P10

void delay_c_100ms()
{
    unsigned char i, j;
    i = 193;
    j = 128;
    do
    {
        while (--j)
            ;
    } while (--i);
}

void delay_inline_asm_100ms()
{
    __asm__(
        "   push 0x30\n"
        "   push 0x31\n"
        "   mov 0x30,#2\n"
        "   mov 0x31,#3\n"
        "DELAY_NEXT00:\n"
        "   djnz 0x31,DELAY_NEXT00\n"
        "   djnz 0x30,DELAY_NEXT00\n"
        "   pop 0x31\n"
        "   pop 0x30\n");
}

void main()
{
    while (1)
    {
        // delay_inline_asm_100ms();
        // LED = !LED;

        DELAY100MS();
        LED = !LED;

        // delay_c_100ms();
        // LED = !LED;
    }
}