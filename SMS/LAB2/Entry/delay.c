#include "delay.h"
void DelayTick(void){
	if (time!=0)
		time--;
}

void Delay(unsigned int ms){
	time = ms;
	while(time>0)
		;
	// testowanie czy jest on wiekszy od 0z
}	
