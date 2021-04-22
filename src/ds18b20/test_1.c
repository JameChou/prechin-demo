#include <8052.h>
#include "lib_onewire.h"
#include "lib_lcd1602.h"

void main(void)
{
    lcd_1602_init();
    unsigned int ack = onewire_init();
    lcd_show_int_num(1, 1, ack, 3);
    
    while (1) {

    }
}