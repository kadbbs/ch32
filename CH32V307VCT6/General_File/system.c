#include <ch32v30x_gpio.h>
#include <ch32v30x_rcc.h>
#include <core_riscv.h>
#include "system.h"

#include "debug.h"
void system_init(){

    //GPIO��ʼ��

//    GPIO_SetBits(GPIOE, GPIO_Pin_0);
    //�жϳ�ʼ��
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

////�жϳ�ʼ��
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
//��ʼ����ʱ���ж�
void Interrupt_Init(void)
   {
      NVIC_InitTypeDef NVIC_InitStructure={0};
      NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn ;
      NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //��ռ���ȼ�
      NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //�����ȼ�
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
volatile uint16_t LED_Status = 0; // �ж���ʹ�õı����� volatile �ɵ���ȫ�ֱ���

//�ⲿ�жϴ�����
void EXTI0_IRQHandler(void)
{
    EXTI_ClearFlag(EXTI_Line0); // ���жϱ�־λΪ��
    LED_Status = !LED_Status ;  // �� LED ״ֵ̬ȡ��
    GPIO_WriteBit(GPIOE, GPIO_Pin_11, LED_Status); // ���� PE11 (�� LED1) ״̬
}

//��ʱ���жϴ�����
//volatile uint16_t LED_Status = 0; // �ж���ʹ�õı����� volatile �ɵ���ȫ�ֱ���
   void TIM6_IRQHandler(void)
   {
      TIM_ClearFlag(TIM6, TIM_FLAG_Update);//�����־λ
      LED_Status = !LED_Status ;  // �� LED ״ֵ̬ȡ��
      GPIO_WriteBit(GPIOE, GPIO_Pin_11, LED_Status); // ���� PE11 (�� LED1) ״̬
   }

//��ʱ���жϳ�ʼ����
//��    ��        : arr���Զ���װֵ��psc Ԥ��Ƶϵ��
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
uint32_t time =0;
typedef enum{
    key_up,
    key_downshake,
    key_down,
    key_upshake

}state_t;

typedef struct{
    state_t state;//���ְ���״̬
    uint8_t volatile cnt;//�¼���ʱ
    uint8_t auxiliary_flag;//״̬������λ,�ж�˫������ʼ��Ϊ��
}value_t;

typedef enum{
    key_null,
    key_click,
    key_doucli,
    key_long

}key_event_all;


value_t value={key_up,0,0};
uint8_t key_event=key_null;//�������¼�

/*�жϰ���״̬
 *
 * */
void key_scan(void){
    if(value.cnt>5){
        value.cnt=0;
        switch(value.state){
            case key_up:{
                if(value.auxiliary_flag){
                    if(value.cnt>500){
                        key_event=key_doucli;
                    }else{
                        key_event=key_click;
                    }

                    value.auxiliary_flag=0;

                }
                break;
            }
            case key_upshake:{
                break;
            }
            case key_down:{
                break;
            }
            case key_downshake:{
                break;
            }
        }

    }

}
/*������ʽ��ͬ��led ��˸��ͬ
 * ���������л�
 * ˫������
 * �������ƣ�led1&led2��������˸
 *
*/
void key_led_multi(){

    if(key_event==key_click){

    }else if(key_event==key_doucli){

    }else if(key_event==key_long){

    }
}

