/*PE7 MISO
 * PE8 LED
 * PE9 SCK       时钟
 * PE10 MOSI
 * PE11 DC         0命令              1data
 *
 * PE12 RESET  0复位使能
 *
 *
 *
 * */



#include "debug.h"
#include "st7789.h"
//st7789引脚初始化
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
 *功能：向lcd驱动芯片写一个命令
 *参数uint_8 reg
 *
 * */
void lcd_write_reg(void){

}

/*
 *
 * lcd_write_data
 *
 * 功能：向lcd驱动芯片写一个数据
 *参数uint_8 data
 *
 * */

void lcd_write_data(){




}

