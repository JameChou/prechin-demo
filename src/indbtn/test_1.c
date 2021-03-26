#include <8052.h>
#include "lib_jce51.h"

#define BTN P2
#define POSITION_C P0
#define DS P1

void main()
{
    uint i = 0;
    int display_num[] = {0, 0, 0, 0, 0, 0, 0, 0};
    const uchar position_arr[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    const uchar number_arr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F};

    uchar t = BTN;
    while (1) {
        if (BTN < 0xFF) {
            delay(1000);
            if (BTN < 0xFF) {
                // 表明按键被按下了
                int j, num;
                for (j = 0; j < 8; j++) {
                    num = t % 2;
                    t /= 2;

                    // 表明是第几位被按下
                    if (num == 0) {
                        int dnum = display_num[j];
                        dnum = dnum >= 9 ? 0 : dnum + 1;
                        display_num[j] = dnum;
                    }
                }
            }
            // 直到按键被松开
            while(BTN < 0xFF);
        }

        // 显示
        for (i=0; i<=7; i++) {
            POSITION_C = position_arr[i];
            DS = number_arr[displayNum[i]];
            delay(100);
        }
    }
}