#include <8052.h>

typedef unsigned char u8;
typedef unsigned int u16;

#define LED P0

#define rol(value, bits) ((value << bits) | (value >> (sizeof(value)*8 - bits)))
#define ror(value, bits) ((value >> bits) | (value << (sizeof(value)*8 - bits)))

void delay(u16 delayParam)
{
    while(delayParam--);
}

void main()
{
    u16 i;
    // 1111 1110
    u8 value = 0xFE;
    while(1) {
        for (i=0; i<7; i++) {
            value = rol(value, 1);
            LED = value;
            delay(50000);
        }
    }
}