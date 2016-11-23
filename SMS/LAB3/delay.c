#include "delay.h"

void DelayTick(void){
	if(msc > 0) --msc;
}

void Delay_ms(unsigned int ms){
	Delay(ms*100);
}

void Delay(unsigned int cnt){
	msc = cnt;
	while(msc > 0);
}	

