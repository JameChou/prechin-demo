#include <8052.h>
#include "lib_jce51.h"

#define LED P0

void main()
{
    int i;
    LED = 0x01;

    delay(50000);
    while (1) {
        for (i=0; i<8; i++) {
            LED = (0x01 << i);
            delay(50000);
        }
    }
}