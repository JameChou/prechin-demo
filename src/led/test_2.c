#include <8052.h>
#include "lib_jce51.h"

#define LED P0_0

void main()
{
   LED = 0;
   for (;;) {
      delay(1000);
      LED = 1;
      delay(1000);
      LED = 0;
   }
}