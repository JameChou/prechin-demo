#include <8052.h>
#include "../../e51.h"

// 位移寄存器
#define SRCLK P3_6
#define RCLK P3_5
#define SER P3_4

void delay(uint delayParam) {
    while (delayParam--);
}

void writeHc595ByteData(uchar serData) {
    SRCLK = 1;
    RCLK = 1;

    int i;

    for (i=0; i<8; i++) {
        SER = serData >> 7;
        serData <<= 1;

        SRCLK = 0;
        _nop_();
        _nop_();
        SRCLK = 1;
    }

    RCLK = 0;
    _nop_();
    _nop_();
    RCLK = 1;
}

void main() {
    uchar ledNum;

    ledNum = 0xFE;

    while (1) {
        writeHc595ByteData(ledNum);
        ledNum = rol(ledNum, 1);
        delay(50000);
    }

}
