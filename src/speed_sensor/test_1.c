#include <8052.h>
#include "lib_i2c.h"
#include "lib_at24c02.h"
#include "lib_jce51.h"
#include "lib_lcd1602.h"
#include "lib_indbtn.h"
#include "lib_timer.h"

static unsigned int counter = 0;

// 初始化外部中断 配置
void out_interrupt_init()
{
    EA = 1;
    IT0 = 1;
    EX0 = 1;

    IT1 = 1;
    EX1 = 1;
}

void main(void)
{
    out_interrupt_init();
    lcd_1602_init();
    timer_1_initer();

    lcd_show_string(1, 6, "ms");
    lcd_show_string(2, 6, "us");
    lcd_show_string(1, 12, "km/h");

    TR1 = 0;
    
    while (1) {
    }
}

void int0_routine() __interrupt 0
{
    // 当第一次计数开始之后才允许再计数中断
    TR1 = 1;
    TL1 = 0xB0;		//设置定时初值
	TH1 = 0x3C;
    counter = 0;
}

void int1_routine() __interrupt 2
{
    // 不再允许计数中断
    TR1 = 0;

    unsigned char min_ms = TL1;
    unsigned char max_ms = TH1;

    unsigned int v = (max_ms * 256 + min_ms) - 15536;

    lcd_show_int_num(1, 1, counter * 50, 5);
    lcd_show_int_num(2, 1, v, 5);

    unsigned int speed = (1.5 / ((counter + v / 1000.0) / 1000)) * 0.036;
    lcd_show_int_num(1, 10, speed, 2);
}

void timer_counter() __interrupt 3
{
    TL1 = 0xB0;		//设置定时初值
	TH1 = 0x3C;

    counter++;

    P2_0 = !P2_0;
}