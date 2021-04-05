#include <8052.h>
#include "lib_jce51.h"
#include "lib_serial.h"

void uart_init() // 4800波特率
{
    // SCON -> SM0/FE(0) SM1(1) SM2(0) REN(1)
    SCON = 0x50;
    // PCON -> SMOD(1) SMOD0(0) 0 0 0 0
    PCON = 0x80;
    // 8位自动重载寄存器 初始值设置 计算方式为
    // 最大为256(0xFF + 1)，这里设置为243 相差13，在12MHz的晶振系统下为13us
    // 则为1/13us = 0.07962MHz(溢出率） / 16 = 0.004807MHz = 4807Hz（波特率）
    TL1 = 0xF3;
    TH1 = 0xF3;

    ET1 = 0; // 关闭定时器中断只使用期计数模式
    TR1 = 1;

    // 开启定时/计数器1
    TMOD &= 0x0F;
    TMOD |= 0x20;
}

void uart_send_byte(unsigned char send_byte)
{
    SBUF = send_byte;
    // 等待上次已经发送完成才进行处理
    while (TI == 0);
    // 查看芯片手册文档，这里需要软件手动把T1进行更新标志位
    T1 = 0;
}
