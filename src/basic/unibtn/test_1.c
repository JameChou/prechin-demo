#include <8052.h>

typedef unsigned int u16;
typedef unsigned char u8;

#define DS P0
#define UNIBTN P2

void delay(u16 delayParam) {
    while (delayParam--);
}

void main() {
    const u8 DS_HEX_ARRAY[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86,
                               0x8E, 0xFF};

    u8 dsIndex = 0;
    for (;;) {
        UNIBTN = 0x0F;

        if (UNIBTN != 0x0F) {
            delay(1000);

            if (UNIBTN != 0x0F) {
                // 确定列
                UNIBTN = 0x0F;
                switch (UNIBTN) {
                    // 第一列下面依次类推
                    case 0x07:
                        dsIndex = 0;
                        break;
                    case 0x0B:
                        dsIndex = 1;
                        break;
                    case 0x0D:
                        dsIndex = 2;
                        break;
                    case 0x0E:
                        dsIndex = 3;
                        break;
                }

                // 确定行
                UNIBTN = 0xF0;
                switch (UNIBTN) {
                    // 第一行下面依次类推
                    case 0x70:
                        break;
                    case 0xB0:
                        dsIndex += 4;
                        break;
                    case 0xD0:
                        dsIndex += 8;
                        break;
                    case 0xE0:
                        dsIndex += 12;
                        break;
                }

                char a = 0;
                while (a < 50 && UNIBTN != 0xF0) { // 按键释放检测
                    delay(100);
                    a++; // 标志位进行强制退出循环
                }
            }
        }

        DS = DS_HEX_ARRAY[dsIndex];
    }
}