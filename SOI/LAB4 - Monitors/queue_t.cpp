
#include "queue_t.h"
#include "Monitors.h"
#include <iostream>
#define BUFFER_SIZE 9


queue_t::queue_t() : readersCounter(0), buffer_state(0) ,czyCzytelnik1Czytal(false), czyCzytelnik2Czytal(false){



    
}

queue_t::~queue_t() {
    
}

void queue_t::push(char element) {
    enter();
    while(buffer_state == BUFFER_SIZE)
		wait(PUSTY);

    	q.push(element);
    	buffer_state++;
    	std::cout << "Pushed element: " << element << std::endl;
    	std::cout << "Buffer state: " << buffer_state << std::endl;
        std::cout << std::endl;

    if(buffer_state == 1)
	{
    		signal(PELNY);
	}
    leave();

 
}
void queue_t::read_element1() {

    readEnter();
	readersCounter += 1;
	if (readersCounter == 1)
		enter();
    readLeave();

    while(czyCzytelnik1Czytal == true)
        wait(MOZNA_CZYTAC1);
    while(buffer_state == 0)
	wait(PELNY);

    readEnter();
    	std::cout << "Reader1 read element: " << q.front() << std::endl;
        std::cout << std::endl;  
        czyCzytelnik1Czytal=true;
    if(czyCzytelnik2Czytal == false)
        	signal(KTOS_PRZECZYTAL);
    readLeave();

    readEnter();
	readersCounter--;
	if(readersCounter == 0 )
		 leave();
    readLeave();
}

void queue_t::read_element2() {
   
    readEnter();
	readersCounter += 1;
	if (readersCounter == 1)
		enter();
    readLeave();

    while(czyCzytelnik2Czytal == true)
        wait(MOZNA_CZYTAC2);
    while(buffer_state == 0)
	wait(PELNY);

    readEnter();
    	std::cout << "Reader2 read element: " << q.front() << std::endl;
        std::cout << std::endl;
        
        czyCzytelnik2Czytal=true;
    if(czyCzytelnik1Czytal == false)
        	signal(KTOS_PRZECZYTAL);
    readLeave();

    readEnter();
	readersCounter--;
	if(readersCounter == 0 )
		 leave();
    readLeave();
}

void queue_t::pop() {
    enter();

    while(czyCzytelnik1Czytal == false && czyCzytelnik2Czytal == false)
	{
		wait(KTOS_PRZECZYTAL);

	}

    while(buffer_state == 0)
        {
		wait(PELNY);        	
	}
    	std::cout << "Consumer popped element: " << q.front() << std::endl;
        buffer_state--;
        std::cout << "Buffer state: " << buffer_state << std::endl;
        std::cout << std::endl;
  	q.pop();
    double numberToChoose = rand()%2;
    if( numberToChoose < 1 )
    {
	    if(czyCzytelnik1Czytal == true)
	    {
	    	czyCzytelnik1Czytal = false;
		signal(MOZNA_CZYTAC1);
	    }
	    if(czyCzytelnik2Czytal == true)
	    {
	    	czyCzytelnik2Czytal = false;
		signal(MOZNA_CZYTAC2);
	    }
     }
     else
     {
     	    if(czyCzytelnik2Czytal == true)
	    {
	    	czyCzytelnik2Czytal = false;
		signal(MOZNA_CZYTAC2);
	    }	
            if(czyCzytelnik1Czytal == true)
	    {
	    	czyCzytelnik1Czytal = false;
		signal(MOZNA_CZYTAC1);
	    }
     }
     if(buffer_state == BUFFER_SIZE - 1)
	{
		signal(PUSTY);
	}
     leave();

}
