#include <8052.h>

#define RELAY P1_4

void main()
{
    RELAY = 0;
    for (;;) {}
}
