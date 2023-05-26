#ifndef _ST7789_H
#define _ST7789_H

#define LCD_WIDTH 320
#define LCD_HEIHGT 240
/*PE7 MISO
 * PE8 LED
 * PE9 SCK       时钟
 * PE10 MOSI
 * PE11 DC         0命令              1data
 * PE12 RESET  0复位使能
 * */
//#define LCD_PWR(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_PIN_7, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET))
#define LCD_RST(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_PIN_12, SET) : GPIO_WriteBit(GPIOE, GPIO_PIN_12, RESET))
#define LCD_DC(n)   (n ? GPIO_WriteBit(GPIOE, GPIO_PIN_11, SET) : GPIO_WriteBit(GPIOE, GPIO_PIN_11, RESET))
//#define LCD_CS(n)   (n ? GPIO_WriteBit(GPIOE, GPIO_PIN_7, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET))
#define LCD_SDA(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_PIN_7, SET) : GPIO_WriteBit(GPIOE, GPIO_PIN_7,RESET)
#define LCD_SCK(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_PIN_9, SET) : GPIO_WriteBit(GPIOE, GPIO_PIN_9, RESET))
#define LCD_LED(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_Pin_8, SET) : GPIO_WriteBit(GPIOE, GPIO_Pin_8, RESET))


void ST7789_GPIO_init(void);

void lcd_write_reg(void);
void lcd_write_data(void);

#endif
