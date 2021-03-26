#ifndef JCE51_JCE51_H
#define JCE51_JCE51_H

typedef unsigned int uint;
typedef unsigned char uchar;

#define rol(value, bits) ((value << bits) | (value >> (sizeof(value)*8 - bits)))
#define ror(value, bits) ((value >> bits) | (value << (sizeof(value)*8 - bits)))

#define _nop_() __asm nop __endasm

/**
 *  @param delay_param delay hl counter
 */ 
void delay(unsigned int delay_param);

#endif