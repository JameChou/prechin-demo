#include <8052.h>
#include "../../e51.h"

#define RCLK P3_6
#define RCK P3_5
#define SER P3_4

void delay(uint delay_param)
{
    while (delay_param--);
}

void write_HC595_data(uchar data1, uchar data2)
{
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

void main()
{
    uchar led_negative_arr[] = {0x0C, 0x1E, 0x3E, 0x7C, 0x7C, 0x3E, 0x1E, 0x0C};
    uchar led_positive_arr[] = {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE};

    int i;

    while (1) {
        for (i=0; i<8; i++) {
            write_HC595_data(led_positive_arr[i], led_negative_arr[i]);
            delay(10);
        }
    }
}
