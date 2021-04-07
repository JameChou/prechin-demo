#ifndef E51_LIB_DS1302_H
#define E51_LIB_DS1302_H

// 1302使能口
#define DS1302_CE P2_5
// 1302IO口
#define DS1302_IO P2_4
// 1302时钟口
#define DS1302_SCLK P2_3

#define DS1302_COMMAND_BASE 0x80

/**
 * 写一个字节数据
 *
 * @param command 指令
 * @param data 数据
 */
void ds1302_write_byte(unsigned char command, unsigned char data);

/**
 * 读取数据
 *
 * @param command 指令
 * @return 读取的数据
 */
unsigned char ds1302_read_byte(unsigned char command);

/**
 * 向ds1302写入数据
 *
 * @param format 格式化
 * @param data 数据
 */
void ds1302_write(unsigned int format, unsigned char data);

/**
 * 读取所有时间数据
 *
 * @return 时间数据数组
 */
unsigned char* ds1302_read(void);

/**
 * 初始化DS1302时钟
 */
void ds1302_init(void);

#endif //E51_LIB_DS1302_H
