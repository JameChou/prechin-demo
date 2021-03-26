#include <8052.h>
#include "lib_jce51.h"

#define LC P1_0
#define CLK P1_2
#define QH P1_4
#define LED P3

uchar read_72HC165(void)
{
    uchar indata, i;

    LC = 0;
    _nop_();
    LC = 1;

    indata = 0;
    for (i=0; i<8; i++) {
        indata = indata << 1;
        CLK = 0;
        _nop_();
        indata |= QH;
        CLK = 1;
    }

    return indata;
}

void main()
{
    uchar h165_value;

    LED = 0xFF;

    while (1) {
        h165_value = read_72HC165();
        if (h165_value != 0xFF) {
            LED = h165_value;
        }
    }

}