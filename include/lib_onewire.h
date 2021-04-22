#ifndef E51_LIB_ONEWIRE_H
#define E51_LIB_ONEWIRE_H


/**
 * 初始化单总线
 */
unsigned char onewire_init(void);

/**
 * 发送一个bit数据
 * 
 * @param bit_data 一个比特数据 
 */
void onewire_send_one_bit(unsigned char bit_data);

/**
 * 接收一个bit数据
 * 
 * @return 接收到的一个比特数据
 */
unsigned char onewire_receive_one_bit(void);

/**
 * 发送一个字节数据
 * 
 * @param byte_data 一个字节数据
 */ 
void onewire_send_one_byte(unsigned char byte_data);

/**
 * 接收一个字节数据
 * 
 * @return 返回一个字节数据
 */ 
unsigned char onewire_receive_one_byte(void);
#endif