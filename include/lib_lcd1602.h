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

/**
 * 显示字符串
 *
 * @param line 第几行 limit (1, 2)
 * @param column 第几列 from 1, 46
 * @param show_string 要显示的字符串
 */
void lcd_show_string(unsigned int line, unsigned int column, unsigned char *show_string);

/**
 * 显示10进制数字
 *
 * @param line 第几行 limit (1, 2)
 * @param column 第几列 from 1, 46
 * @param num 要显示的数字
 * @param length 显示数字的长度
 */
void lcd_show_int_num(unsigned int line, unsigned int column, unsigned int num, unsigned int length);

/**
 * 显示带符号的数字
 *
 * @param line 第几行 limit (1, 2)
 * @param column 第几列 from 1, 46
 * @param num 要显示的数字
 * @param length 数字的长度
 */
void lcd_show_dec_num(unsigned int line, unsigned int column, int num, unsigned int length);

/**
 * 显示16进制数字
 *
 * @param line 第几行 limit (1, 2)
 * @param column 第几列 from 1, 46
 * @param hex_num 要显示的数字
 * @param length 数字长度
 */
void lcd_show_hex_num(unsigned int line, unsigned int column, unsigned char hex_num, unsigned int length);

/**
 * 显示二进制数字
 *
 * @param line 第几行 limit(1, 2)
 * @param column 第几列 from 1, 46
 * @param bin_num 要显示的数字
 * @param length 数字长度
 */
void lcd_show_bin_num(unsigned int line, unsigned int column, unsigned int bin_num, unsigned int length);


#endif //E51_LIB_LCD1602_H
