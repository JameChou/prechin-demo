#include <8052.h>
#include "lib_i2c.h"
#include "lib_at24c02.h"
#include "lib_jce51.h"
#include "lib_lcd1602.h"

void main()
{
    lcd_1602_init();

    /*
    at24c02_write(1, 66);
    delay(7000);
     */

    unsigned char num = at24c02_read(1);
    lcd_show_int_num(1, 1, num, 3);

    while (1) {
    }
}