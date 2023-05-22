#ifndef __SYSTEM_H
#define __SYSTEM_H
void system_init();
void system_loop();
void GPIO_init();
void EXTI0_INT_INIT(void);
void led_loop(void);

//volatile uint16_t led_status=0;
#endif
