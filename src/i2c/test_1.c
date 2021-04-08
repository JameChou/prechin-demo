#include <8052.h>
#include "lib_i2c.h"
#include "lib_at24c02.h"
#include "lib_jce51.h"
#include "lib_lcd1602.h"
#include "lib_indbtn.h"

unsigned int num = 0, key_num;

void main()
{
    lcd_1602_init();
    lcd_show_string(1, 1, "Hello");

    while (1) {
        key_num = check_ind_btn_index();

        switch (key_num) {
            case 0:
                num++;
                lcd_show_int_num(1, 1, num, 5);
                break;
            case 1:
                num--;
                lcd_show_int_num(1, 1, num, 5);
                break;
            case 2:
                at24c02_write(0, num % 256);
                delay(5000);
                at24c02_write(1, num / 256);

                lcd_show_string(2, 1, "Flash ok!");
                delay(10000);
                lcd_show_string(2, 1, "         ");
                break;
            case 3:
                num = at24c02_read(0);
                num |= at24c02_read(1) << 8;
                lcd_show_string(2, 1, "Read ok!");
                delay(10000);
                lcd_show_string(2, 1, "        ");

                lcd_show_int_num(1, 1, num, 5);
        }
    }
}