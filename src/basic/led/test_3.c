#include <8052.h>

typedef unsigned char u8;
typedef unsigned int u16;

#define LED P0

void delay(u16 delayParam) 
{
    while (delayParam--);
}

void main()
{
    u8 i;
    LED = 0x01;

    delay(50000);
    while (1) {
        for (i=0; i<8; i++) {
            LED = (0x01 << i);
            delay(50000);
        }
    }
}