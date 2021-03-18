#include <e51.h>

void delay(u16 delayParam)
{
    while (delayParam--);
}