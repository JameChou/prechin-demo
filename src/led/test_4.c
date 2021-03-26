#include <8052.h>
#include "lib_jce51.h"

#define LED P0

void main()
{
    int i;
    // 1111 1110
    uchar value = 0xFE;
    while(1) {
        for (i=0; i<7; i++) {
            value = rol(value, 1);
            LED = value;
            delay(50000);
        }
    }
}