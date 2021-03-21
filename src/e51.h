#ifndef E51_E51_H
#define E51_E51_H

typedef unsigned int uint;
typedef unsigned char uchar;

#define rol(value, bits) ((value << bits) | (value >> (sizeof(value)*8 - bits)))
#define ror(value, bits) ((value >> bits) | (value << (sizeof(value)*8 - bits)))

#define _nop_() __asm nop __endasm

#endif //E51_E51_H
