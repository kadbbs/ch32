#include <ch32v30x_gpio.h>
#include <ch32v30x_rcc.h>
#include <core_riscv.h>
#include "system.h"

#include "debug.h"
void system_init(){

    //GPIO初始化

//    GPIO_SetBits(GPIOE, GPIO_Pin_0);
    //中断初始化
    EXTI0_INT_INIT();
    GPIO_init();
}

void GPIO_init(){
    GPIO_InitTypeDef GPIO_init_structure={0};

        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
        GPIO_init_structure.GPIO_Pin=GPIO_Pin_11;
        GPIO_init_structure.GPIO_Mode=GPIO_Mode_Out_PP;
        GPIO_init_structure.GPIO_Speed=GPIO_Speed_50MHz;
        GPIO_Init(GPIOE,&GPIO_init_structure);
}

////中断初始化
//void EXTI0_INT_INIT(void)
//{
//    GPIO_InitTypeDef GPIO_InitStructure = {0};
//    EXTI_InitTypeDef EXTI_InitStructure = {0};
//    NVIC_InitTypeDef NVIC_InitStructure = {0};
//
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//
//    /* GPIOA ----> EXTI_Line0 */
//    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
//    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
//    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
//    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//    EXTI_Init(&EXTI_InitStructure);
//
//    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//}
//初始化定时器中断
void Interrupt_Init(void)
   {
      NVIC_InitTypeDef NVIC_InitStructure={0};
      NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn ;
      NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //抢占优先级
      NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //子优先级
      NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
      NVIC_Init(&NVIC_InitStructure);
   }

//void EXTI0_INT_INIT(void)
//{
//    GPIO_InitTypeDef GPIO_InitStructure = {0};
//    EXTI_InitTypeDef EXTI_InitStructure = {0};
//    NVIC_InitTypeDef NVIC_InitStructure = {0};
//
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);
//
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//
//    /* GPIOA ----> EXTI_Line0 */
//    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
//    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
//    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
////    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
//    EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
//    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//    EXTI_Init(&EXTI_InitStructure);
//
//    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//}



void system_loop(){


//    GPIO_WriteBit(GPIOE,GPIO_Pin_11,1);
//    Delay_Ms(500);
            u8 i=0;
            u8 j=0;
            Delay_Init();

            Delay_Ms(250);
            GPIO_WriteBit(GPIOA, GPIO_Pin_0, (i==0)?(i=Bit_SET):(i=Bit_RESET));
            Delay_Ms(250);
            GPIO_WriteBit(GPIOA, GPIO_Pin_1, (j==0)?(j=Bit_SET):(j=Bit_RESET));


}

void led_loop(){
    u16 i=0;
    u16 j=1;
            Delay_Ms(250);

            GPIO_WriteBit(GPIOE, GPIO_Pin_11, (i==0)?(i=Bit_SET):(i=Bit_RESET));
            Delay_Ms(250);
            GPIO_WriteBit(GPIOE, GPIO_Pin_12, (j==0)?(j=Bit_SET):(j=Bit_RESET));
}
volatile uint16_t LED_Status = 0; // 中断里使用的变量加 volatile 可当成全局变量

//外部中断处理函数
void EXTI0_IRQHandler(void)
{
    EXTI_ClearFlag(EXTI_Line0); // 置中断标志位为零
    LED_Status = !LED_Status ;  // 将 LED 状态值取反
    GPIO_WriteBit(GPIOE, GPIO_Pin_11, LED_Status); // 配置 PE11 (即 LED1) 状态
}

//定时器中断处理函数
//volatile uint16_t LED_Status = 0; // 中断里使用的变量加 volatile 可当成全局变量
   void TIM6_IRQHandler(void)
   {
      TIM_ClearFlag(TIM6, TIM_FLAG_Update);//清除标志位
      LED_Status = !LED_Status ;  // 将 LED 状态值取反
      GPIO_WriteBit(GPIOE, GPIO_Pin_11, LED_Status); // 配置 PE11 (即 LED1) 状态
   }

//定时器中断初始函数
//输    入        : arr：自动重装值，psc 预分频系数
void TIM6_Init( u16 arr, u16 psc)
  {
     TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;

     RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM6, ENABLE );

     TIM_TimeBaseInitStructure.TIM_Period = arr;
     TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
     TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
     TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Down;
     TIM_TimeBaseInit( TIM6, &TIM_TimeBaseInitStructure);

     TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
     TIM_ARRPreloadConfig( TIM6, ENABLE );
     TIM_Cmd( TIM6, ENABLE );
  }


