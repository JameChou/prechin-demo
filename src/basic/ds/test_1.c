#include <8052.h>

typedef unsigned int u16;

#define DS P0

// 1100 0000 0
#define ZERO 0xC0
// 1111 1001 1
#define ONE 0xF9
// 1010 0100 2
#define TWO 0xA4
// 1011 0000 3
#define THREE 0xB0
// 1001 1001 4
#define FOUR 0x99
// 1001 0010 5
#define FIVE 0x92
// 1000 0010 6
#define SIX 0x82
// 1111 1000 7
#define SEVEN 0xF8
// 1000 0000 8
#define EIGHT 0x80
// 1001 0000 9
#define NINE 0x90

void delay(u16 delayParam)
{
    while(delayParam--);
}

void main()
{
    while (1)
    {
        DS = ZERO;
        delay(5000000);
        DS = ONE;
        delay(5000000);
        DS = TWO;
        delay(5000000);
        DS = THREE;
        delay(5000000);
        DS = FOUR;
        delay(5000000);
        DS = FIVE;
        delay(5000000);
        DS = SIX;
        delay(5000000);
        DS = SEVEN;
        delay(5000000);
        DS = EIGHT;
        delay(5000000);
        DS = NINE;
        delay(5000000);
    }
}
