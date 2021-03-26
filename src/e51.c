#include <e51.h>

void delay(u16 delay_param)
{
    while (delay_param--);
}