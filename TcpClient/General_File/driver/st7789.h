#ifndef _ST7789_H
#define _ST7789_H
#define u8 uint8_t
#define LCD_WIDTH 240
#define LCD_HEIHGT 320
#include "debug.h"
#define delay_ms  Delay_Ms

//������ɫ
#define WHITE            0xFFFF
#define BLACK            0x0000
#define BLUE             0x001F
#define BRED             0XF81F
#define GRED             0XFFE0
#define GBLUE            0X07FF
#define RED              0xF800
#define MAGENTA          0xF81F
#define GREEN            0x07E0
#define CYAN             0x7FFF
#define YELLOW           0xFFE0

/*PE7 MISO
 * PE8 LED
 * PE9 SCK       ʱ��
 * PE10 MOSI
 * PE11 DC         0����              1data
 * PE12 RESET  0��λʹ��
 * */
//#define LCD_PWR(n)  (n ? GPIO_WriteBit(GPIOE, GPIO_Pin_13, SET) : GPIO_WriteBit(GPIOE, GPIO_Pin_13, RESET))
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
void lcd_write_ram(void);

void lcd_set_address(u16 x1, u16 y1, u16 x2, u16 y2);


void lcd_display_on(void);




void lcd_display_off(void);


void lcd_clear(u16 color);

void lcd_draw_point(u16 x, u16 y, u16 color);
void lcd_show_char(u16 x, u16 y, u8 num, u8 size, u8 mode);
void lcd_show_string(u16 x, u16 y, u16 width, u16 height, u8 *p, u8 size, u8 mode);
void lcd_show_chinese(u16 x, u16 y, const u8 * ch, u16 size, u8 n, u8 mode);


void lcd_init(void);

//typedef struct
//{
//    u16 width;          //LCD ���
//    u16 height;         //LCD �߶�
//    u16 id;             //LCD ID
//    u8  dir;            //���������������ƣ�0��������1��������
//    u8  wramcmd;        //��ʼдgramָ��
//    u8  setxcmd;        //����x����ָ��
//    u8  setycmd;        //����y����ָ��
//}_lcd_dev;



#endif
