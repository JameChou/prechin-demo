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
    if (P3_0 == 0) {
        delay(500);

        if (P3_0 == 0) {
            return 0;
        }
    }

    if (P3_1 == 0) {
        delay(500);
        if (P3_1 == 0) {
            return 1;
        }
    }

    return 100;
}