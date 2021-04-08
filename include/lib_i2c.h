#ifndef E51_LIB_I2C_H
#define E51_LIB_I2C_H

// i2c 时钟线
#define I2C_SCL P2_0
// i2c sda线
#define I2C_SDA P2_1

/**
 * i2c 开始
 */
void i2c_start();

/**
 * i2c 发送一个字节数据
 * @param data 数据
 */
void i2c_send_byte(unsigned char data);

/**
 * i2c 读取一个字节数据
 *
 * @return 一个字节数据
 */
unsigned char i2c_read_byte();

/**
 * i2c 发送一个应答
 *
 * @param ack 应答
 */
void i2c_send_ack(unsigned char ack);

/**
 * i2c 接收一个应答
 *
 * @return 应答数据
 */
unsigned char i2c_receive_ack();

/**
 * 结束i2c通信
 */
void i2c_stop();

#endif //E51_LIB_I2C_H
