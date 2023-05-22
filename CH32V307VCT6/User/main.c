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


void EXTI0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
volatile uint16_t LED_Status = 0; // 中断里使用的变量加 volatile 可当成全局变量
void EXTI0_IRQHandler(void)
{
    EXTI_ClearFlag(EXTI_Line0); // 置中断标志位为零
    LED_Status = !LED_Status ;  // 将 LED 状态值取反
    GPIO_WriteBit(GPIOE, GPIO_Pin_11, LED_Status); // 配置 PE11 (即 LED1) 状态
}


int main(void)
{
//	Delay_Init();
//	USART_Printf_Init(115200);
//	printf("SystemClk:%d\r\n",SystemCoreClock);
//    system_init();
    EXTI0_INT_INIT();
    GPIO_init();
//    u16 i=0;
//    u16 j=1;
//    Delay_Init();
//    GPIO_WriteBit(GPIOE, GPIO_Pin_11,1);
//    GPIO_WriteBit(GPIOE, GPIO_Pin_12,1);
	while(1)
    {
////        system_loop();
//	    Delay_Ms(250);
//
//	    GPIO_WriteBit(GPIOE, GPIO_Pin_11, (i==0)?(i=Bit_SET):(i=Bit_RESET));
//	    Delay_Ms(250);
//	    GPIO_WriteBit(GPIOE, GPIO_Pin_12, (j==0)?(j=Bit_SET):(j=Bit_RESET));
//	    EXTI_ClearITPendingBit(EXTI_Line0);
//	    EXTI0_led();


	}
}

