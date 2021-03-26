#include <8052.h>
#include "../../e51.h"

// 位移寄存器
#define SRCLK P3_6
#define RCLK P3_5
#define SER P3_4

void delay(uint delay_param)
{
    while (delay_param--);
}

void write_HC595_byte_data(uchar ser_data)
{
    SRCLK = 1;
    RCLK = 1;

    int i;

    for (i=0; i<8; i++) {
        SER = ser_data >> 7;
        ser_data <<= 1;

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

void main()
{
    uchar ledNum;

    ledNum = 0xFE;

    while (1) {
        write_HC595_byte_data(ledNum);
        ledNum = rol(ledNum, 1);
        delay(50000);
    }

}
