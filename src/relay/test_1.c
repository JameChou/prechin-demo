#include <8052.h>
#include "lib_jce51.h"

#define RELAY P1_4

void main()
{
    RELAY = 0;
    for (;;) {}
}
