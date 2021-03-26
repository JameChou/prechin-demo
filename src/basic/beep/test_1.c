#include <8052.h>


typedef unsigned int u16;

#define BEEP P0_5

void delay(u16 delay_param)
{
    while(delay_param--);
}

void main()
{
    BEEP = 1;
    while (1) {
        BEEP = !BEEP;
        delay(10);
    }
    /*
     * 声音大小调节
     */
    /*
    while (1)
    {
        BEEP = 1;
        delay(10);
        BEEP = 0;
        delay(5);
    }
     */
}

