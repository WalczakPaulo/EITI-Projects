#include <stm32f10x.h>
#include <stdbool.h>

#define LED1 GPIO_Pin_8
#define LED2 GPIO_Pin_9
#define LED3 GPIO_Pin_10
#define LED4 GPIO_Pin_11
#define LED5 GPIO_Pin_12
#define LED6 GPIO_Pin_13
#define LED7 GPIO_Pin_14
#define LED8 GPIO_Pin_15
#define LEDALL (LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8)
enum LED_ACTION { LED_ON, LED_OFF, LED_TOGGLE };

#define SW0 GPIO_Pin_0
#define SW1 GPIO_Pin_1
#define SW2 GPIO_Pin_2
#define SW3 GPIO_Pin_3
#define SWALL (SW0|SW1|SW2|SW3)
enum SW_OPERATION { SW_AND, SW_OR };

void LED(uint16_t led, enum LED_ACTION act);
bool SW(uint16_t sw);
bool SW_MANY(uint16_t sw, enum SW_OPERATION op);

//void Set50usTimer(uint32_t ticks35, uint32_t ticks15);
//void Start50usTimer(void);
//void Stop50usTimer(void);
//void Reset50usTimer(void);
//void SetTimeout(__IO uint32_t msec);
//bool TimeoutPassed(void);
//bool Ist15Expired(void);
//bool Ist35Expired(void);
//bool Is50usTimerStarted(void);
//void TimeoutTick(void);

void Communication_Mode(bool rx, bool tx);
uint8_t Communication_Get(void);
void Communication_Put(uint8_t c);
void Enable50usTimer(void);
void Disable50usTimer(void);
