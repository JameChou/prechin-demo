#include <8052.h>
#include "lib_jce51.h"

#define POSITION_C P0
#define DS P1

void main()
{
    uint i;
    const uchar position_arr[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    const uchar number_arr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F};

    while (1) {
        for (i=0; i<=7; i++) {
            POSITION_C = position_arr[i];
            switch (i) {
                case 0:
                    DS = number_arr[1];
                    break;
                case 1:
                    DS = number_arr[0];
                    break;
                case 2:
                    DS = number_arr[2];
                    break;
                case 3:
                    DS = number_arr[4];
                    break;
                case 4:
                    DS = number_arr[2];
                    break;
                case 5:
                    DS = number_arr[0];
                    break;
                case 6:
                    DS = number_arr[4];
                    break;
                case 7:
                    DS = number_arr[8];
                    break;
                default:
                    DS = number_arr[0];
                    break;
            }

            delay(100);
        }
    }
}