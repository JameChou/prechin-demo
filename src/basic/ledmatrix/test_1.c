#include <8052.h>
#include "../../e51.h"

#define RCLK P3_6
#define RCK P3_5
#define SER P3_4

void delay(uint delayParam) {
    while (delayParam--);
}

void writeHC595Data(uchar data1, uchar data2) {
    RCLK = 1;
    RCK = 1;

    int i;

    for (i=0; i<8; i++) {
        SER = data1 >> 7;
        data1 <<= 1;

        RCLK = 0;
        _nop_();
        _nop_();
        RCLK = 1;
    }

    for (i=0; i<8; i++) {
        SER = data2 >> 7;
        data2 <<= 1;

        RCLK = 0;
        _nop_();
        _nop_();
        RCLK = 1;
    }

    RCK = 0;
    _nop_();
    _nop_();
    RCK = 1;
}

void main() {
    uchar data1, data2;
    data1 = 0xFE;
    data2 = 0x01;

    while (1) {
        writeHC595Data(data1, data2);
        delay(100);
    }
}
