#ifndef E51_LIB_SERIAL_H
#define E51_LIB_SERIAL_H

// 串口通信相关header

/**
 * 初始化uart
 */
void uart_init();
/**
 * 发送一个字节数据
 *
 * @param send_byte 串口数据
 */
void uart_send_byte(unsigned char send_byte);

#endif //E51_LIB_SERIAL_H
