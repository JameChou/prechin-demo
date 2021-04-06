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
