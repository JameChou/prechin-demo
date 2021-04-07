#include <8052.h>
#include "lib_lcd1602.h"
#include "lib_ds1302.h"

void main(void)
{
    lcd_1602_init();
    ds1302_init();

    lcd_show_string(1, 1, "  -  -  ");
    lcd_show_string(2, 1, "  :  :  ");

    // 55秒
    ds1302_write(1, 0x55);
    // 30分
    ds1302_write(2, 0x30);
    // 16时
    ds1302_write(3, 0x16);
    // 2021年
    ds1302_write(4, 0x21);
    // 04月
    ds1302_write(5, 0x04);
    // 05日
    ds1302_write(6, 0x05);

    while (1) {
        unsigned char *read_date = ds1302_read();
        lcd_show_int_num(1, 1, read_date[3], 2);
        lcd_show_int_num(1, 4, read_date[4], 2);
        lcd_show_int_num(1, 7, read_date[5], 2);
        lcd_show_int_num(2, 7, read_date[0], 2);
        lcd_show_int_num(2, 4, read_date[1], 2);
        lcd_show_int_num(2, 1, read_date[2], 2);
    }
}