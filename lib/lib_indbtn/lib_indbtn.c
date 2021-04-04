#include <8052.h>
#include "lib_jce51.h"
#include "lib_indbtn.h"

/**
 * 检测独立按键P0系列口时的处理
 *
 * @return
 */
uint check_ind_btn_index_p0()
{
    if (P0 < 0xFF) {
        delay(1000);

        if (P0 < 0xFF) {
            int j, num;
            uchar t = P0;
            for (j = 0; j < 8; j++) {
                num = t % 2;
                t /= 2;

                if (!num) return j;
            }
        }
    }

    return 0;
}

/**
 * 检测独立按键P0系列口时的处理
 *
 * @return
 */
uint check_ind_btn_index_p1()
{
    if (P1 < 0xFF) {
        delay(1000);

        if (P1 < 0xFF) {
            int j, num;
            uchar t = P1;
            for (j=0; j<8; j++) {
                num = t % 2;
                t /= 2;

                if (!num) return j;
            }
        }
    }

    return 0;
}

/**
 * 检测独立按键P0系列口时的处理
 *
 * @return
 */
uint check_ind_btn_index_p2()
{
    if (P2 < 0xFF) {
        delay(1000);

        if (P2 < 0xFF) {
            int j, num;
            uchar t = P2;
            for (j=0; j<8; j++) {
                num = t % 2;
                t /= 2;

                if (!num) return j;
            }
        }
    }

    return 0;
}

/**
 * 检测独立按键P0系列口时的处理
 *
 * @return
 */
uint check_ind_btn_index_p3()
{
    if (P3 < 0xFF) {
        delay(1000);

        if (P3 < 0xFF) {
            int j, num;
            uchar t = P3;

            for (j=0; j<8; j++) {
                num = t % 2;
                t /= 2;

                if (!num) return j;
            }
        }
    }

    return 0;
}
