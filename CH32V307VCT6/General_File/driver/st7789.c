/*PE7 MISO
 * PE8 LED
 * PE9 SCK       ʱ��
 * PE10 MOSI
 * PE11 DC         0����              1data
 *
 * PE12 RESET  0��λʹ��
 *
 *
 *
 * */



#include "debug.h"
#include "st7789.h"
//st7789���ų�ʼ��
void ST7789_GPIO_init(){
    GPIO_InitTypeDef GPIO_init_structure={0};

        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
        GPIO_init_structure.GPIO_Pin=GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;
        GPIO_init_structure.GPIO_Mode=GPIO_Mode_Out_PP;
        GPIO_init_structure.GPIO_Speed=GPIO_Speed_50MHz;
        GPIO_Init(GPIOE,&GPIO_init_structure);
}

/*
 *
 * lcd_write_reg
 *
 *���ܣ���lcd����оƬдһ������
 *����uint_8 reg
 *
 * */
void lcd_write_reg(void){

}

/*
 *
 * lcd_write_data
 *
 * ���ܣ���lcd����оƬдһ������
 *����uint_8 data
 *
 * */

void lcd_write_data(){




}

