#include "stm32f10x.h"
static unsigned int msc = 0; // zmienna przechowujaca czas pozostaly czas opoznienia
static unsigned int numberOfQuants = 0; //nowa zmienna
void DelayTick(void);        // aktualizacja czasu opoznienia
void Delay(unsigned int);    // ustawienie czasu opoznienia i zawieszenie dzialania programu
void Delay_ms(unsigned int); // ustawienie czasu opoznienia i zawieszenie dzialania programu (argument okresla liczbe ms)
