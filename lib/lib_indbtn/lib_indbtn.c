#include <8052.h>
#include "lib_jce51.h"
#include "lib_indbtn.h"

/**
 * 检测独立按键P0系列口时的处理
 *
 * @return
 */
uint check_ind_btn_index()
{
    if (P3_3 == 0) {
        delay(1000);

        while (P3_3 == 0);

        return 0;
    }

    if (P3_4 == 0) {
        delay(1000);

        while (P3_4 == 0);
        return 1;
    }

    if (P3_5 == 0) {
        delay(1000);

        while (P3_5 == 0);

        return 2;
    }

    if (P3_6 == 0) {
        delay(1000);

        while (P3_6 == 0);

        return 3;
    }

    return 100;
}