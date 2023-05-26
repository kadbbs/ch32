#ifndef _ST7789_H
#define _ST7789_H
#define u8 uint8_t
#define LCD_WIDTH 320
#define LCD_HEIHGT 240
#include "debug.h"
#define delay_ms  Delay_Ms

/*PE7 MISO
 * PE8 LED
 * PE9 SCK       时钟
 * PE10 MOSI
 * PE11 DC         0命令              1data
 * PE12 RESET  0复位使能
 * */
#define LCD_PWR(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_Pin_13, SET) : GPIO_WriteBit(GPIOE, GPIO_Pin_13, RESET))
#define LCD_RST(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_Pin_12, SET) : GPIO_WriteBit(GPIOE, GPIO_Pin_12, RESET))
#define LCD_WR(n)   (n ? GPIO_WriteBit(GPIOE, GPIO_Pin_11, SET) : GPIO_WriteBit(GPIOE, GPIO_Pin_11, RESET))
#define LCD_CS(n)   (n ? GPIO_WriteBit(GPIOE, GPIO_Pin_14, SET) : GPIO_WriteBit(GPIOE, GPIO_Pin_14, RESET))
#define LCD_SDA(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_Pin_10, SET) : GPIO_WriteBit(GPIOE, GPIO_Pin_10,RESET))
#define LCD_SCK(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_Pin_9, SET) : GPIO_WriteBit(GPIOE, GPIO_Pin_9, RESET))
#define LCD_LED(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_Pin_8, SET) : GPIO_WriteBit(GPIOE, GPIO_Pin_8, RESET))


void ST7789_GPIO_init(void);

void lcd_write_reg(u8 reg);
void lcd_write_data(u8 data);

void lcd_init(void);

#endif
