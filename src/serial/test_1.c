#include <8052.h>
#include "lib_jce51.h"
#include "lib_serial.h"

void main()
{
    uart_init();
    uart_send_byte(0x69);
    while (1) {
    }
}

// uart中断优先级为4 这里需要设置
void uart_routine() __interrupt 4
{

    P3_7 = 0;
    // 表示接收数据
    if (RI == 1) {
        P0 = ~SBUF;

        RI = 0;
    }
}