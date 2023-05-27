#ifndef __SYSTEM_H
#define __SYSTEM_H
void system_init();
void system_loop();
void GPIO_init();
void EXTI0_INT_INIT(void);
void led_loop(void);
void EXTI0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM6_IRQHandler(void)   __attribute__((interrupt("WCH-Interrupt-fast")));

//volatile uint16_t led_status=0;
#endif
