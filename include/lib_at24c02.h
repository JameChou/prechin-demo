#ifndef E51_LIB_AT24C02_H
#define E51_LIB_AT24C02_H

// write address 如果要读 SLAVE_ADDRESS |= 1;
#define SLAVE_ADDRESS 0xA0

/**
 * 向ROM写一个数据
 *
 * @param word_address 存储数据的ROM地址
 * @param data 数据
 */
void at24c02_write(unsigned char word_address, unsigned char data);

/**
 * 从ROm中读一个数据
 *
 * @param word_address 存储数据的ROM地址
 * @return 读取的数据
 */
unsigned char at24c02_read(unsigned char word_address);

#endif //E51_LIB_AT24C02_H
