#include "lint.h"
#include "STC89xx.h"

#define LED P10
#define F_CPU 12000000L
#define TIM_1MS (65536-F_CPU/12/1000)   // 1ms
#define MS_COUNT 200 // 200x1ms

unsigned char count;
void timer0_init()
{
    TMOD = 0x01;
    TL0 = TIM_1MS;
    TH0 = TIM_1MS >> 8;

    TR0 = 1;
    ET0 = 1;
    EA = 1;
    count = MS_COUNT;   // 200ms
}

void timer0_isr(void) __interrupt(1) __using(1) 
{
    TL0 = TIM_1MS;
    TH0 = TIM_1MS >> 8;

    if (--count)
        return;

    count = MS_COUNT;
    LED = !LED;
}

void main()
{
    timer0_init();
    while(1)
    ;
}