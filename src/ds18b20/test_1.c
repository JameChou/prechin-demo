#include <8052.h>
#include "lib_lcd1602.h"
#include "lib_onewire.h"
#include "lib_ds18b20.h"

float temperature;

void main(void)
{
    lcd_1602_init();
    lcd_show_string(1, 1, "Temperature:");
    
    while (1) {
        ds18b20_init();

        temperature = read_ds18b20_temperature();

        if (temperature < 0) {
            lcd_show_char(2, 1, '-');
            temperature = -temperature;
        } else {
            lcd_show_char(2, 1, '+');
        }

        lcd_show_int_num(2, 2, temperature, 3);
        lcd_show_char(2, 5, '.');
        lcd_show_int_num(2, 6, (unsigned long) (temperature * 10000) % 10000, 4);
    }
}