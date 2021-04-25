#ifndef E51_LIB_DS18B20_H
#define E51_LIB_DS18B20_H

/**
 * 初始化ds18b20
 */
void ds18b20_init(void);

/**
 * 读取ds18b20 温度数据 
 * 
 * @return 温度数据
 */
float read_ds18b20_temperature();



#endif