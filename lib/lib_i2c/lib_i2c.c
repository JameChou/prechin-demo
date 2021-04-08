#include <8052.h>
#include "lib_i2c.h"

void i2c_start()
{
    I2C_SDA = 1;
    // 这里要严格按照I2C的顺序来写
    // 只有SCL在高电平下才会处理SDA相关顺序
    I2C_SCL = 1;
    I2C_SDA = 0;
    I2C_SCL = 0;
}

void i2c_send_byte(unsigned char data)
{
    unsigned int i;

    for (i=0; i<8; i++) {
        // 在SCL拉高电平之前可以更改SDA，顺序如果写成
        /*
         *  I2C_SCL = 1;
         *  I2C_SDA = data & (0x80 >> i);
         *
         *  这样是无法正确写入数据的
         */
        I2C_SDA = data & (0x80 >> i);
        I2C_SCL = 1;

        I2C_SCL = 0;
    }
}

unsigned char i2c_read_byte()
{
    unsigned char data = 0x00, i;

    // 这里释放SDA总线
    I2C_SDA = 1;

    for (i=0; i<8; i++) {
        // 同write要严格按照顺序来写
        I2C_SCL = 1;
        if (I2C_SDA) {
            data |= 0x80 >> i;
        }
        I2C_SCL = 0;
    }
    return data;
}

void i2c_send_ack(unsigned char ack)
{
    // 给从机应答，拉高SCL电平之前更改SDA数据
    I2C_SDA = ack;
    I2C_SCL = 1;
    I2C_SCL = 0;
}

unsigned char i2c_receive_ack()
{
    unsigned char ack;

    // 释放SDA总线
    I2C_SDA = 1;

    // 拉高SCL电平读取数据
    I2C_SCL = 1;
    ack = I2C_SDA;
    I2C_SCL = 0;

    return ack;
}

void i2c_stop()
{
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}