#include <8052.h>
#include "lib_timer.h"
#include "lib_jce51.h"
#include "lib_indbtn.h"

static uint led_mod;

#define P2_PORT P2

void main()
{
    led_mod = 1;
    uint check_btn = 100;
    timer_0_initer();
    P2_PORT &= 0xFE;

    while(1) {
        check_btn = check_ind_btn_index();
        if (check_btn < 100) {
            led_mod = check_btn;
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

    if (i >= 1000) {
        if (led_mod == 0) {
            if (P2_PORT == 0xEF) {
                P2_PORT &= 0xFE;
            } else {
                P2_PORT = rol(P2_PORT, 1);
            }
        } else {
            if (P2_PORT == 0xFE) {
                P2_PORT &= 0xEF;
            } else {
                P2_PORT = ror(P2_PORT, 1);
            }
        }
        i = 0;
    }
}