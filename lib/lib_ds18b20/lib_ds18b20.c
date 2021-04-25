#include <8052.h>
#include "lib_onewire.h"
#include "lib_ds18b20.h"

void ds18b20_init(void)
{
    onewire_init();
    onewire_send_one_byte(0xCC);
    onewire_send_one_byte(0x44);
}

float read_ds18b20_temperature()
{
    onewire_init();
    onewire_send_one_byte(0xCC);
    onewire_send_one_byte(0xBE);

    unsigned char lsb = onewire_receive_one_byte();
    unsigned char msb = onewire_receive_one_byte();

    int temp;
    float temperature;

    temp = (msb << 8) | lsb;

    temperature = temp / 16.0;

    return temperature;
}