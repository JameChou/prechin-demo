#include <8052.h>

typedef unsigned int u16;
typedef unsigned char u8;

#define BTN P2
#define POSITION_C P0
#define DS P1

void delay(u16 delayParam)
{
    while(delayParam--);
}

void main()
{
    u16 i = 0;
    int displayNum[] = {0, 0, 0, 0, 0, 0, 0, 0};
    const u8 positionArr[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    const u8 numberArr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F};

    while (1) {
        if (BTN < 0xFF) {
            delay(1000);
            if (BTN < 0xFF) {
                // 表明按键被按下了
                int j, num;
                for (j = 0; j < 8; j++) {
                    num = BTN % 2;
                    BTN /= 2;

                    // 表明是第几位被按下
                    if (num == 0) {
                        int dnum = displayNum[j];
                        dnum = dnum >= 9 ? 0 : dnum + 1;
                        displayNum[j] = dnum;
                    }
                }
            }
            // 直到按键被松开
            while(BTN < 0xFF);
        }

        // 显示
        for (i=0; i<=7; i++) {
            POSITION_C = positionArr[i];
            DS = numberArr[displayNum[i]];
            delay(100);
        }
    }
}