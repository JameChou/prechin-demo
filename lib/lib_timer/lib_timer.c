#include <8052.h>

/**
 * 初始化定时器0 16位
 */
void timer_0_initer()
{
    // 先将Timer0相关的数据清0
    TMOD &= 0xF0;
    // Timer0 可以处理
    TMOD |= 0x01;

    // IE,XICON寄存器 开关配置
    ET0 = 1;
    // 中断允许控制位
    EA = 1;

    // T0溢出中断标志，当产生溢出时，由硬件置"1"TF0
    TF0 = 0;

    // 定时器0的允许控制位
    TR0 = 1;

    // 12MHz的晶振1000为一毫秒时间
    // 溢出位最小8bit
    TL0 = 0x18;
    // 溢出位最大8bit
    TH0 = 0xFC;
}

void timer_1_initer()
{
    TMOD &= 0x0F;
    TMOD |= 0x10;

    ET1 = 1;
    EA = 1;
    
    TF1 = 0;
    TR1 = 1;

    // 50ms处理一次中断 从15536开始计数
	TL1 = 0xB0;		//设置定时初值
	TH1 = 0x3C;
}