#include "8052.h"

#define LED P0_0

void delay(int delayParam)
{
   while (delayParam > 0) {
      delayParam--;
   }
}

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