#include <8052.h>
#include "../../e51.h"

#define LED P2_0

void timer0Init() {
    TMOD |= 0x01;
    TH0 = 0xFC;
    TL0 = 0x18;

    ET0 = 1;
    EA = 1;
    TR0 = 1;
}

void main() {
    timer0Init();
    while (1);
}

void timer0() __interrupt 1 {
    static uint i;
    TH0 = 0xFC;
    TL0 = 0x18;
    i++;

    if (i == 1000) {
        i = 0;
        LED = !LED;
    }
}
