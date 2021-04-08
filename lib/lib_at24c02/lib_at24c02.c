#include <8052.h>
#include "lib_i2c.h"
#include "lib_at24c02.h"

void at24c02_write(unsigned char word_address, unsigned char data)
{
    i2c_start();
    i2c_send_byte(SLAVE_ADDRESS);
    i2c_receive_ack();
    i2c_send_byte(word_address);
    i2c_receive_ack();
    i2c_send_byte(data);
    i2c_receive_ack();
    i2c_stop();
}

unsigned char at24c02_read(unsigned char word_address)
{
    unsigned char data = 0x00, slave_address_read = SLAVE_ADDRESS | 0x01;

    i2c_start();
    i2c_send_byte(SLAVE_ADDRESS);
    i2c_receive_ack();
    i2c_send_byte(word_address);
    i2c_receive_ack();
    i2c_start();
    i2c_send_byte(slave_address_read);
    i2c_receive_ack();
    data = i2c_read_byte();
    i2c_send_ack(1);
    i2c_stop();

    return data;
}
