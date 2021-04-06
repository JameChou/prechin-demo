#include <8052.h>
#include "lib_lcd1602.h"

void main()
{
    lcd_1602_init();

    lcd_show_char(1, 1, 'A');

    while (1) {}
}
