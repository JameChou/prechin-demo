#include <8052.h>
#include "../../e51.h"

#define LED P2_0
#define K3 P3_2

void delay(uint delayParam) {
    while (delayParam--);
}

void int0Init() {
    IT0 = 1;
    EX0 = 1;
    EA = 1;
}

void main() {
    int0Init();
    while (1);
}

void int0() __interrupt 0 {
    delay(1000);

    if (K3 == 0) {
        LED = !LED;
    }
}