#include "../../e51.h"
#include <8052.h>

#define MOTO P1_0

void delay(uint delayParam) {
    while (delayParam--);
}

void main() {
    int i;

    MOTO = 0;
    for (i=0; i<100; i++) {
        MOTO = 1;
        delay(5000);
    }

    MOTO = 0;
    while (1) {}
}
