#ifndef E51_E51_H
#define E51_E51_H

typedef unsigned int u16;
typedef unsigned char u8;

void delay(u16 delayParam);

#define rol(value, bits) ((value << bits) | (value >> (sizeof(value)*8 - bits)))
#define ror(value, bits) ((value >> bits) | (value << (sizeof(value)*8 - bits)))

#endif //E51_E51_H
