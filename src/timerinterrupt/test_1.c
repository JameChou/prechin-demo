#include <8052.h>
#include "lib_timer.h"
#include "lib_jce51.h"
#include "lib_indbtn.h"

static uint key_num, led_mod;

#define LED P0

void main()
{
    // 初始化定时器
    timer_0_initer();
    key_num = 0;
    led_mod = 0;
    P0 = 0xFE;

    while (1) {
        key_num = check_ind_btn_index_p1();

        if (key_num == 0) {
            led_mod = 0;
            continue;
        }

        if (key_num == 1) {
            led_mod = 1;
            continue;
        }
    }
}

/**
 * 定时器中断处理方法
 */
void timer_interrupt_method() __interrupt 1
{
    static uint i;

    TH0 = 0xFC;
    TL0 = 0x18;
    i++;

    if (i >= 500) {
        switch (key_num) {
            case 0:
                LED = rol(LED, 1);
                break;
            case 1:
                LED = ror(LED, 1);
                break;
            default:
                LED = 0xFF;
                break;
        }
    }
}