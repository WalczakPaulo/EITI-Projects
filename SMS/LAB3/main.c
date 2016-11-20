/****************************************
 * projekt01: RCC configuration         *
 ****************************************/
#include "modbus_conf.h"
#include "modbus.h"
#include "stm32f10x.h"
#include "lcd_hd44780.h"
#include "delay.h"
#include "misc.h"
#include "main.h"
#include <stdbool.h> 		// true, false
#include <stdio.h>

char wyniki[19];
void RCC_Config(void);	
void GPIO_Config(void); 
void NVIC_Config(void);	
void TIM2_Config(void);	
void TIM4_Config(void);	
void ADC1_Config(void);	
void USART1_Config(void);
char KB2char(void);
void LCD_Refresh(uint16_t tempADC);

float temp;
uint8_t read_temp[] = {0x00, 0x00, 0x00, 0x01};
uint8_t *resp;
uint16_t resplen;
uint16_t temperature;
MB_RESPONSE_STATE respstate;
uint16_t tempADC;
float floatTemp;
uint8_t fan_on[] = {0x00,0x01,0x01,0xFF};
uint8_t fan_off[] = {0x00,0x01,0x00,0x00};
uint8_t heat_on[] = {0x00,0x04,0x01,0xFF};
uint8_t heat_off[] = {0x00,0x04,0x00,0x00};

int main(void) {
  RCC_Config();		  // konfiguracja RCC
  GPIO_Config();    // konfiguracja GPIO
	NVIC_Config();		// konfiguracja NVIC
	TIM2_Config();		// konfigruacja TIM2
	TIM4_Config();		// konfiguracja TIM4
	ADC1_Config();		// konfiguracja ADC1
	USART1_Config();	// konfiguracja USART1
	MB_Config(115200);// konfiguracja MB
	
	SysTick_Config( 720 ); // 10us
	NVIC_SetPriority(SysTick_IRQn, 0 ); 
	SysTick_CLKSourceConfig( SysTick_CLKSource_HCLK );
	
	LCD_Initialize(); // inicjalizacja LCD
	
	while(1) {
		// ,,Regulator''
		
		 MB_SendRequest( 101, 0x04, read_temp, 4);
		 respstate = MB_GetResponse( 101, 0x04, &resp , & resplen , 1000);
		if(respstate != RESPONSE_OK){
			LCD_GoTo(0,0);
			LCD_WriteText("Blad");
		}
		else {temperature  = (resp[1]<<8);
		temperature += resp[2];
		floatTemp = (float) temperature;
		LCD_GoTo(0,1);
		sprintf(wyniki,"%2.1f *C" ,floatTemp/100 );
		LCD_WriteText(wyniki);
			}
		LCD_Refresh(tempADC);
		if (floatTemp/100>25)
		{
				MB_SendRequest(101, FUN_WRITE_SINGLE_REGISTER, fan_on,4);
			  respstate = MB_GetResponse( 101, 0x04, &resp , & resplen , 1000);
			  MB_SendRequest(101, FUN_WRITE_SINGLE_REGISTER, heat_off,4);
			respstate = MB_GetResponse( 101, 0x04, &resp , & resplen , 1000);
			  
		}
		else if (floatTemp/100<=24.1)
		{
				MB_SendRequest(101, FUN_WRITE_SINGLE_REGISTER, fan_off,4);
			  respstate = MB_GetResponse( 101, 0x04, &resp , & resplen , 1000);
			  MB_SendRequest(101, FUN_WRITE_SINGLE_REGISTER, heat_on,4);
			respstate = MB_GetResponse( 101, 0x04, &resp , & resplen , 1000);
			  
		}
		Delay_ms(500);
	}
}


void USART1_Config(){
	USART_InitTypeDef USART_InitStruct;
		

  USART_InitStruct.USART_BaudRate = 115200;
  USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStruct.USART_WordLength = USART_WordLength_9b;
  USART_InitStruct.USART_Parity = USART_Parity_Even;
  USART_InitStruct.USART_StopBits = USART_StopBits_1;
  USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

  USART_Init(USART1, &USART_InitStruct);
  USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
  USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
	
	USART_Cmd(USART1, ENABLE);
}

void Communication_Mode(bool rx, bool tx){ // TODO
	USART_ITConfig(USART1, USART_IT_RXNE, rx?ENABLE:DISABLE);
  USART_ITConfig(USART1, USART_IT_TXE , tx?ENABLE:DISABLE);
}

void Communication_Put(uint8_t ch){ // TODO
	USART_SendData(USART1, ch);
}

uint8_t Communication_Get(void){ // TODO
	
	uint8_t tmp = USART_ReceiveData(USART1);
  SetCharacterReceived(false);
  return tmp;
	
}

void Enable50usTimer(void){ // TODO
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
}

void Disable50usTimer(void){ // TODO
	TIM_ITConfig(TIM4, TIM_IT_Update, DISABLE);
}

void NVIC_Config(void){
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
  NVIC_PriorityGroupConfig( 0 );
	
	// Klawiatura PD6 -> EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource6);
	EXTI_InitStructure.EXTI_Line = EXTI_Line6;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	// Klawiatura PD7 -> EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource7);
	EXTI_InitStructure.EXTI_Line = EXTI_Line7;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	// Klawiatura PD8 -> EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource8);
	EXTI_InitStructure.EXTI_Line = EXTI_Line8;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	// Klawiatura PD9 -> EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource9);
	EXTI_InitStructure.EXTI_Line = EXTI_Line9;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	// Klawiatura -- EXTI9_5_IRQn
	NVIC_ClearPendingIRQ(EXTI9_5_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3; // Konfiguracja priorytetow TODO
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;        // Konfiguracja priorytetow TODO
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	// Przetwornik ADC -- ADC1_2_IRQn
	NVIC_ClearPendingIRQ(ADC1_2_IRQn);
	NVIC_EnableIRQ(ADC1_2_IRQn);
	NVIC_InitStructure.NVIC_IRQChannel = ADC1_2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	// USART1 -- USART1_IRQn
	// TODO
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	
	// TIM4 (timer 50us) -- TIM4_IRQn
	// TODO	
	
	NVIC_ClearPendingIRQ(TIM4_IRQn);                    // wyczyszczenie bitu przerwania
	NVIC_EnableIRQ(TIM4_IRQn);                          // wlaczenie obslugi przerwania
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;     // nazwa przerwania
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; // priorytet wywlaszczania
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  // podpriorytet
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;     // wlaczenie
	NVIC_Init(&NVIC_InitStructure); 
}

void RCC_Config(void) {
  ErrorStatus HSEStartUpStatus;                          // zmienna opisujaca rezultat 
  							                                         // uruchomienia HSE
  // konfigurowanie sygnalow taktujacych
  RCC_DeInit();                                          // reset ustawien RCC
  RCC_HSEConfig(RCC_HSE_ON);                             // wlacz HSE
  HSEStartUpStatus = RCC_WaitForHSEStartUp();            // czekaj na gotowosc HSE
  if(HSEStartUpStatus == SUCCESS) {
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);//
    FLASH_SetLatency(FLASH_Latency_2);                   // zwloka Flasha: 2 takty 
																												 // dla 72MHz
    RCC_HCLKConfig(RCC_SYSCLK_Div1);                     // HCLK = SYSCLK
    RCC_PCLK2Config(RCC_HCLK_Div1);                      // PCLK2 = HCLK
    RCC_PCLK1Config(RCC_HCLK_Div2);                      // PCLK1 = HCLK/2
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9); // PLLCLK = HSE*9 
																												 // czyli 8MHz * 9 = 72 MHz
    RCC_PLLCmd(ENABLE);                                  // wlacz PLL
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);  // czekaj na uruchomienie PLL
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);           // ustaw PLL jako zrodlo 
																							  				 // sygnalu zegarowego
    while(RCC_GetSYSCLKSource() != 0x08);                // czekaj az PLL bedzie 
                                                         // sygnalem zegarowym systemu    
		RCC_ADCCLKConfig(RCC_PCLK2_Div6);                    // ADCCLK = PCLK2/6 = 12 MHz
	
    // konfiguracja sygnalow taktujacych uzywanych peryferii 
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);// wlacz taktowanie timera TIM2
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , ENABLE);// wlacz taktowanie timera TIM2
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4 , ENABLE);// wlacz taktowanie timera TIM4
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);// wlacz taktowanie portu AFIO
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 , ENABLE);// wlacz taktowanie ADC1
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);// wlacz taktowanie portu GPIO A
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);// wlacz taktowanie portu GPIO B
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);// wlacz taktowanie portu GPIO C
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);// wlacz taktowanie portu GPIO D
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);// wlacz taktowanie portu GPIO E
		// wlacz taktowanie USART1
		// TODO
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); // wlacz taktowanie USART1
  }
}

void GPIO_Config(void) {
  // konfigurowanie portow GPIO
  GPIO_InitTypeDef  GPIO_InitStructure; 
	
	GPIO_InitTypeDef GPIO_InitStruct;

  // Pin nadawczy nalezy skonfigurowac jako "alternative function, push-pull"
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStruct);

  // Pin odbiorczy nalezy skonfigurowac jako wejscie "plywajace"
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStruct);
		
	// Konfiguracja wejscia analogowego (PB0) -- wejscie analogowe
	// TODO
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	// Konfiguracja LEDALL (PB8-PB15) -- wyjscie, push-pull
	GPIO_InitStructure.GPIO_Pin = LEDALL;             		// pin 0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      // wejscie w trybie analogous
	GPIO_Init(GPIOB, &GPIO_InitStructure);                // inicjalizacja portu B
	
	// Konfiguracja klawiatury (PD10-PD13) -- wyjscie, otwarty dren
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	// Konfiguracja klawiatury (PD6-PD9) -- wejscie plywajace
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOD, GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13);
}

void LCD_Refresh(uint16_t tempADC){
	LCD_GoTo(0,0);
  temp	= (((tempADC * 3.3)/4095) - 0.64) *((90)/2.56) - 30;
	sprintf(wyniki,"%2.1f *C" ,temp );
	LCD_WriteText(wyniki); // wyswietl zawartosc bufora na LCD
	// Wyswietlenie wszystkich informacji jednoczesnie
	// TODO
}

void TIM2_Config(void){
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
		
	TIM_TimeBaseStructure.TIM_Prescaler = 7200-1;
	TIM_TimeBaseStructure.TIM_Period = 5000;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	// konfiguracja kanalu timera
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_Pulse = 1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_ITConfig ( TIM2, TIM_IT_CC2 , ENABLE );
	TIM_Cmd(TIM2, ENABLE);
}
	
void TIM4_Config(void){
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
  TIM_OCInitTypeDef TIM_OCInitStructure;

  TIM_TimeBaseStructure.TIM_Prescaler = 3600-1;               // 72MHz/7200=10kHz
  TIM_TimeBaseStructure.TIM_Period = 1;                   // 10kHz/10000=1Hz (1s)
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; // zliczanie w gore
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;            // brak powtorzen
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);             // inicjalizacja TIM4
	TIM_ITConfig (TIM4, TIM_IT_Update, ENABLE );  // wlaczenie przerwan
	TIM_Cmd(TIM4, ENABLE);                                      // aktywacja timera TIM4


}

void ADC1_Config(void) {
	ADC_InitTypeDef  ADC_InitStructure;
	
	ADC_DeInit(ADC1);                                   // reset ustawien ADC1
	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;  // niezalezne dzialanie ADC 1 i 2
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;       // pomiar pojedynczego kanalu
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE; // pomiar automatyczny
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T2_CC2; // start na przerwanie
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; // pomiar wyrownany do prawej
	ADC_InitStructure.ADC_NbrOfChannel = 1;             // jeden kanal
	ADC_Init(ADC1, &ADC_InitStructure);                 // inicjalizacja ADC1

	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_41Cycles5); // ADC1, kanal 16, 
  ADC_ExternalTrigConvCmd(ADC1, ENABLE);
	ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);
	
	ADC_Cmd(ADC1, ENABLE);                              // aktywacja ADC1
		
	ADC_ResetCalibration(ADC1);                         // reset rejestru kalibracji ADC1
	while(ADC_GetResetCalibrationStatus(ADC1));         // oczekiwanie na koniec resetu
	ADC_StartCalibration(ADC1);                         // start kalibracji ADC1
	while(ADC_GetCalibrationStatus(ADC1));              // czekaj na koniec kalibracji
}

char KB2char(void){
	unsigned int GPIO_Pin_row, GPIO_Pin_col, i, j;
	const unsigned char KBkody[16] = {'1','2','3','A',\
	                                  '4','5','6','B',\
	                                  '7','8','9','C',\
	                                  '*','0','#','D'};
	GPIO_SetBits(GPIOD, GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13);
	GPIO_Pin_row = GPIO_Pin_10;
	for(i=0;i<4;++i){
		GPIO_ResetBits(GPIOD, GPIO_Pin_row);
		Delay_ms(5);
		GPIO_Pin_col = GPIO_Pin_6;
		for(j=0;j<4;++j){
			if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_col) == 0){
				GPIO_ResetBits(GPIOD, GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13);
				return KBkody[4*i+j];
			}
			GPIO_Pin_col = GPIO_Pin_col << 1;
		}
		GPIO_SetBits(GPIOD, GPIO_Pin_row);
		GPIO_Pin_row = GPIO_Pin_row << 1;
	}
	GPIO_ResetBits(GPIOD, GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13);
	return 0;
}

void LED(uint16_t led, enum LED_ACTION act) {
	switch(act){
		case LED_ON: GPIO_SetBits(GPIOB, led); break;
		case LED_OFF: GPIO_ResetBits(GPIOB, led); break;
		case LED_TOGGLE: GPIO_WriteBit(GPIOB, led, (GPIO_ReadOutputDataBit(GPIOB, led) == Bit_SET?Bit_RESET:Bit_SET));
	}
}
