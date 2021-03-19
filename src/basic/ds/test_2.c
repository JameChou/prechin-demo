#include <8052.h>

typedef unsigned int u16;
typedef unsigned char u8;

#define POSITION_C P0
#define DS P1

void delay(u16 delayParam)
{
    while(delayParam--);
}

void main()
{
    u16 i;
    const u8 positionArr[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    const u8 numberArr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F};

    while (1) {
        for (i=0; i<=7; i++) {
            POSITION_C = positionArr[i];
            switch (i) {
                case 0:
                    DS = numberArr[1];
                    break;
                case 1:
                    DS = numberArr[0];
                    break;
                case 2:
                    DS = numberArr[2];
                    break;
                case 3:
                    DS = numberArr[4];
                    break;
                case 4:
                    DS = numberArr[2];
                    break;
                case 5:
                    DS = numberArr[0];
                    break;
                case 6:
                    DS = numberArr[4];
                    break;
                case 7:
                    DS = numberArr[8];
                    break;
                default:
                    DS = numberArr[0];
                    break;
            }

            delay(100);
        }
    }
}