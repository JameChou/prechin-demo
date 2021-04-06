#ifndef E51_LIB_LCD1602_H
#define E51_LIB_LCD1602_H

#define LCD_EN P2_7
#define LCD_RS P2_6
#define LCD_WR P2_5

#define LCD_DATA_PORT P0

// LCD1602工具模块
/**
 * 写指令
 *
 * @param command 指令
 */
void lcd_write_command(unsigned char command);

/**
 * 写数据
 *
 * @param data 数据
 */
void lcd_write_data(unsigned char data);

/**
 * 初始化LCD 1602
 */
void lcd_1602_init(void);

/**
 * 设置AC
 *
 * @param line 第几行 limit 1, 2
 * @param column 第几列 limit 1, 46
 */
void lcd_set_ac(unsigned int line, unsigned int column);

/**
 * 显示字符
 *
 * @param line 第几行 limit 1, 2
 * @param column 第几列 from 1, 46
 * @param show_char 要显示的字符
 */
void lcd_show_char(unsigned int line, unsigned int column, unsigned char show_char);




#endif //E51_LIB_LCD1602_H
