/****************************************
 * wejsciowka 2: Implementacja Delay    *
					Modified By PaulWal
 ****************************************/
#include "stm32f10x.h"
#include "delay.h"
#include <stdbool.h>

void RCC_Config(void);
bool flag = true; // flaga


int main(void){
	RCC_Config();
	// Tutaj skonfigurowac zegar SysTick
		
	while(1){
		flag = !flag; // przelacz flage (warto ja obserwowac w panelu Watch)
		Delay(5000); // odczekaj 5000ms = 5s
	}
}

void RCC_Config(void) {
  // konfigurowanie sygnalow taktujacych
  RCC_DeInit();                           // reset ustawien RCC
	FLASH_SetLatency(FLASH_Latency_0);      // zwloka Flasha: 0 taktow
	RCC_HCLKConfig(RCC_SYSCLK_Div1);        // HCLK=SYSCLK/1
	
	while(RCC_GetSYSCLKSource() != 0x00);   // czekaj az HSI bedzie 
																					// sygnalem zegarowym systemu
  SysTick_Config(8000);
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
	NVIC_SetPriority ( SysTick_IRQn , 0) ;

	//NVIC_SetPriority ( SysTick_IRQn , 0) ;

}
