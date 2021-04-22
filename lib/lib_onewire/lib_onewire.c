#include <8052.h>
#include "lib_onewire.h"

#define ONE_WIRE_PORT P3_7

unsigned char onewire_init(void)
{
    unsigned char i;
    ONE_WIRE_PORT = 1;
    ONE_WIRE_PORT = 0;

    // 延时480us
	i = 247; while (--i);
    ONE_WIRE_PORT = 1;

    // 延时15 ~ 60us -> 70us
    i = 32; while (--i);

    unsigned char ack_bit;

    // 从机应答
    // 若有应答从机会在60~240us内响应主机 将总线拉低
    // 若没有应答，因为这里ONE_WIRE_PORT = 1; 则会保持高电平
    ack_bit = ONE_WIRE_PORT;

    return ack_bit;
}

void onewire_send_one_bit(unsigned char bit_data)
{
    unsigned char i;

    ONE_WIRE_PORT = 1;
    ONE_WIRE_PORT = 0;

    // 延时10us 表示开始发送数据
	i = 4; while (--i);

    // 这时候将总线保持等于需要传输的值
    ONE_WIRE_PORT = bit_data;

    // 这里再延时 46us，总用时在60us左右
    i = 24; while (--i);
    ONE_WIRE_PORT = 1;
}

unsigned char onewire_receive_one_bit(void)
{
    unsigned char i;
    unsigned char bit_data;

    ONE_WIRE_PORT = 0;
    i = 2; while (--i);
    ONE_WIRE_PORT = 1;
    i = 2; while (--i);

    bit_data = ONE_WIRE_PORT;
    i = 24; while (--i);

    return bit_data;
}

void onewire_send_one_byte(unsigned char byte_data)
{
    unsigned char i;

    for (i = 0; i < 8; i++) {
        onewire_send_one_bit(byte_data & (0x01 << i));
    }
}

unsigned char onewire_receive_one_byte(void)
{
    unsigned char i;
    unsigned char receive_byte = 0x00;

    for (i = 0; i < 8; i++) {
        if (onewire_receive_one_bit()) {
            receive_byte |= (0x01 << i);
        }
    }

    return receive_byte;
}