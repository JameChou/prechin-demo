#include <8052.h>
#include "lib_lcd1602.h"

// 12MHz晶振下 1ms延时
void lcd_delay(void)
{
    unsigned char i, j;

    i = 2;
    j = 239;
    do {
        while (--j);
    } while (--i);
}

// 某个数的次方计算
unsigned int lcd_pow(unsigned int num, unsigned int pow)
{
    unsigned int i;
    unsigned int result = 1;

    for (i=0; i<pow; i++) {
        result *= num;
    }

    return result;
}

void lcd_write_command(unsigned char command)
{
    LCD_RS = 0;
    LCD_WR = 0;

    LCD_DATA_PORT = command;
    LCD_EN = 1;
    lcd_delay();
    LCD_EN = 0;
    lcd_delay();
}

void lcd_write_data(unsigned char data)
{
    LCD_RS = 1;
    LCD_WR = 0;

    LCD_DATA_PORT = data;
    LCD_EN = 1;
    lcd_delay();
    LCD_EN = 0;
    lcd_delay();
}

void lcd_1602_init(void)
{
    // AC++,画面不动
    lcd_write_command(0x06);
    // 显示开,光标关,闪烁关
    lcd_write_command(0x0C);
    // 八位数据接口,两行显示,5x7点阵
    lcd_write_command(0x38);
    // 清屏
    lcd_write_command(0x01);
}

void lcd_set_ac(unsigned int line, unsigned int column)
{
    if (line == 1) {
        lcd_write_command(0x80 | (column - 1));
    } else {
        lcd_write_command(0x80 | ((column - 1) + 0x40));
    }
}

void lcd_show_char(unsigned int line, unsigned int column, unsigned char show_char)
{
    lcd_set_ac(line, column);
    lcd_write_data(show_char);
}

void lcd_show_string(unsigned int line, unsigned int column, unsigned char *show_string)
{
    lcd_set_ac(line, column);

    unsigned int i = 0;
    while (show_string[i] != '\0') {
        lcd_write_data(show_string[i]);
        i++;
    }
}

void lcd_show_int_num(unsigned int line, unsigned int column, unsigned int num, unsigned int length)
{
    lcd_set_ac(line, column);
    unsigned int i;

    for (i=length; i>0; i--) {
        lcd_write_data('0' + ((num / lcd_pow(10, i-1)) % 10));
    }
}

void lcd_show_dec_num(unsigned int line, unsigned int column, int num, unsigned int length)
{
    lcd_set_ac(line, column);
    unsigned int single_num, i;

    if (num < 0) {
        single_num = -num;
        lcd_write_data('-');
    } else {
        single_num = num;
        lcd_write_data('+');
    }

    for (i=length; i>0; i--) {
        lcd_write_data('0' + ((single_num / lcd_pow(10, i-1)) % 10));
    }
}

void lcd_show_hex_num(unsigned int line, unsigned int column, unsigned char hex_num, unsigned int length)
{
    lcd_set_ac(line, column);
    unsigned int i, single_num;

    for (i=length; i>0; i--) {
        single_num = hex_num / lcd_pow(16, i-1) % 16;
        if (single_num < 10) {
            lcd_write_data('0' + single_num);
        } else {
            lcd_write_data('A' + single_num - 10);
        }
    }
}

void lcd_show_bin_num(unsigned int line, unsigned int column, unsigned int bin_num, unsigned int length)
{
    lcd_set_ac(line, column);
    unsigned int i;

    for (i=length; i>0; i--) {
        lcd_write_data('0' + bin_num / lcd_pow(2, i-1) % 2);
    }
}

