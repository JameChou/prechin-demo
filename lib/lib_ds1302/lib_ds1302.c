#include <8052.h>
#include "lib_ds1302.h"

// command 读写数组  -> 顺序是年 月 日 时 分 秒
unsigned char command_array[] = {0x0C, 0x08, 0x06, 0x04, 0x02, 0x00};

unsigned char dec_2_bcd(unsigned char dec)
{
    return dec / 10 * 16 + dec % 20;
}

unsigned char bcd_2_dec(unsigned char bcd)
{
    return bcd / 16 * 10 + bcd % 16;
}

void ds1302_init(void)
{
    DS1302_CE = 0;
    DS1302_SCLK = 0;
    DS1302_IO = 0x00;
}

void ds1302_write_byte(unsigned char command, unsigned char data)
{
    DS1302_CE = 1;
    unsigned int i;

    //data = dec_2_bcd(data);

    for (i=0; i<8; i++) {
        // 将command 每一位进行发送处理
        DS1302_IO = command & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }

    for (i=0; i<8; i++) {
        // 将data 每一位进行发送处理
        DS1302_IO = data & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }

    DS1302_CE = 0;
}

unsigned char ds1302_read_byte(unsigned char command)
{
    DS1302_CE = 1;
    unsigned int i;
    unsigned char data = 0x00;

    for (i=0; i<8; i++) {
        DS1302_IO = command & (0x01 << i);
        DS1302_SCLK = 0;
        DS1302_SCLK = 1;
    }
    for (i=0; i<8; i++) {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;

        if (DS1302_IO) {
            data |= (0x01 << i);
        }
    }

    DS1302_CE = 0;
    DS1302_IO = 0;

    return bcd_2_dec(data);
}

void ds1302_write(unsigned int format, unsigned char data)
{
    unsigned char command = DS1302_COMMAND_BASE;
    command |= command_array[(format - 1)];

    ds1302_write_byte(command, data);
}

unsigned char* ds1302_read(void)
{
    unsigned char ret_data[6];
    unsigned int i;

    for (i=0; i<6; i++) {
        ret_data[i] = ds1302_read_byte((DS1302_COMMAND_BASE | command_array[i] | 1));
    }

    return ret_data;
}