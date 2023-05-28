/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/*
 *@Note
 USART Print debugging routine:
 USART1_Tx(PA9).
 This example demonstrates using USART1(PA9) as a print debug port output.

*/

#include "debug.h"

#include "../General_File/system.h"
#include "../General_File/driver/st7789.h"
#include "../General_File/driver/font.h"

/* Global typedef */

/* Global define */

/* Global Variable */


/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
//void EXTI0_led(void) __attribute__((interrupt("WCH-Interrupt-fast")));
//
//volatile uint16_t led_status=1;
//
//void EXTI0_led(){
//
//    EXTI_ClearITPendingBit(EXTI_Line0);
//    led_status=!led_status;
//
//    GPIO_WriteBit(GPIOE, GPIO_Pin_11, led_status);
//
//}







int main(void)
{

//    ST7789_GPIO_init();
//    Delay_Init();
//    uint8_t i=0;
//	while(1)
//    {   i=!i;
//	    LCD_LED(i);
//	    Delay_Ms(2000);
//	}
//    u16 YELLOW=0xff00;
    lcd_init();
    lcd_clear(YELLOW);

        while(1)
        {
//            lcd_show_string(66, 0, 108, 12, "IoT Boardfhuhfuihaiwhfhewfhwhefi", 24, 1);
//            lcd_show_chinese(72, 32, my_name, 32, 3, 1);
//            lcd_show_string(66, 0, 108, 24, "IoT Board", 24, 1);
//            lcd_clear(BLUE);
//            Delay_Ms(100);
//
//            lcd_clear(WHITE);
//            Delay_Ms(100);
//            lcd_clear(BLACK);
//            Delay_Ms(100);
//            lcd_clear(BLUE);
//            Delay_Ms(100);
//            lcd_clear(BRED);
//            Delay_Ms(100);
//            lcd_clear(GRED);
//            Delay_Ms(100);
//            lcd_clear(GBLUE);
//            Delay_Ms(100);
//            lcd_clear(RED);
//            Delay_Ms(100);
//            lcd_clear(MAGENTA);
//            Delay_Ms(100);
//            lcd_clear(GREEN);
//            Delay_Ms(100);
//            lcd_clear(CYAN);
//            Delay_Ms(100);
//            lcd_clear(YELLOW);
//            Delay_Ms(100);
//            lcd_show_chinese(120-16, 160-16, my_name, 32, 1, 1);
//            lcd_show_chinese(120-16, 160+16,yun, 32, 1, 1);
//            lcd_show_chinese(0, 0,win_sign, 128, 1, 1);
//            lcd_show_chinese(0, 0,yehuo, 320, 1, 1);
//            Draw_Circle(80+64,160,80);
//            delay_ms(10);
//            lcd_show_chinese(0, 0,bitmap_sd_bytes, 64, 2, 1);
//            lcd_show_chinese(32, 0,bitmap_wd_bytes, 64, 2, 1);
        }
//
//    while(1);
}

