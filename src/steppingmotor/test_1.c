#include <8052.h>
#include "lib_jce51.h"

#define MOTOA P1_0
#define MOTOB P1_1
#define MOTOC P1_2
#define MOTOD P1_3

void main()
{
    P1 = 0x00;

    while (1) {
        MOTOA = 1;
        MOTOB = 0;
        MOTOC = 1;
        MOTOD = 1;
        delay(200);

        MOTOA = 1;
        MOTOB = 1;
        MOTOC = 1;
        MOTOD = 0;
        delay(200);

        MOTOA = 0;
        MOTOB = 1;
        MOTOC = 1;
        MOTOD = 1;
        delay(200);

        MOTOA = 1;
        MOTOB = 1;
        MOTOC = 0;
        MOTOD = 1;
        delay(200);
    }
}
