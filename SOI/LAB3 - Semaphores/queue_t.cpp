
#include "queue_t.h"
#include <iostream>

queue_t::queue_t() : buffer_state(0) ,czyCzytelnik1Czytal(false), czyCzytelnik2Czytal(false){
    sem_init(&PUSTY,0,9);
    sem_init(&PELNY,0,0);
    pthread_mutex_init(&CZYTELNIK1,NULL);
    pthread_mutex_init(&CZYTELNIK2,NULL);
    pthread_mutex_init(&KSIAZKA_PRZECZYTANA1,NULL);
    pthread_mutex_init(&KSIAZKA_PRZECZYTANA2,NULL);
    pthread_mutex_init(&KTOS_PRZECZYTAL,NULL);
    pthread_mutex_lock(&KTOS_PRZECZYTAL);
}

queue_t::~queue_t() {
    sem_destroy(&PELNY);
    sem_destroy(&PUSTY);
    pthread_mutex_destroy(&CZYTELNIK1);
    pthread_mutex_destroy(&CZYTELNIK2);
    pthread_mutex_destroy(&KSIAZKA_PRZECZYTANA1);
    pthread_mutex_destroy(&KSIAZKA_PRZECZYTANA2);
    pthread_mutex_destroy(&KTOS_PRZECZYTAL);
}

void queue_t::push(char element) {
    sem_wait(&PUSTY);
    pthread_mutex_lock(&CZYTELNIK1);
    pthread_mutex_lock(&CZYTELNIK2);
    	q.push(element);
    	buffer_state++;
    	std::cout << "Pushed element: " << element << std::endl;
    	std::cout << "Buffer state: " << buffer_state << std::endl;
        std::cout << std::endl;
    sem_post(&PELNY);
    pthread_mutex_unlock(&CZYTELNIK1);
    pthread_mutex_unlock(&CZYTELNIK2);

}

void queue_t::read_element1() {
    
    pthread_mutex_lock(&KSIAZKA_PRZECZYTANA1);
    sem_wait(&PELNY);
    pthread_mutex_lock(&CZYTELNIK1);
    sem_post(&PELNY);
    	std::cout << "Reader1 read element: " << q.front() << std::endl;
        std::cout << std::endl;
        czyCzytelnik1Czytal=true;
    pthread_mutex_unlock(&KTOS_PRZECZYTAL);
    pthread_mutex_unlock(&CZYTELNIK1);
}

void queue_t::read_element2() {
    
    pthread_mutex_lock(&KSIAZKA_PRZECZYTANA2);
    sem_wait(&PELNY);
    pthread_mutex_lock(&CZYTELNIK2);
    sem_post(&PELNY);
    	std::cout << "Reader2 read element: " << q.front() << std::endl;
        std::cout << std::endl;
        czyCzytelnik2Czytal=true;
    pthread_mutex_unlock(&KTOS_PRZECZYTAL);
    pthread_mutex_unlock(&CZYTELNIK2);
}

void queue_t::pop() {
    pthread_mutex_lock(&KTOS_PRZECZYTAL);
    sem_wait(&PELNY); 
    pthread_mutex_lock(&CZYTELNIK1);
    pthread_mutex_lock(&CZYTELNIK2);
    	std::cout << "Consumer popped element: " << q.front() << std::endl;
        buffer_state--;
        std::cout << "Buffer state: " << buffer_state << std::endl;
        std::cout << std::endl;
  	q.pop();
    sem_post(&PUSTY);
    if(czyCzytelnik1Czytal==true)
        pthread_mutex_unlock(&KSIAZKA_PRZECZYTANA1);
    if(czyCzytelnik2Czytal==true)
    pthread_mutex_unlock(&KSIAZKA_PRZECZYTANA2);
    czyCzytelnik1Czytal = false;
    czyCzytelnik2Czytal=false;
    pthread_mutex_unlock(&CZYTELNIK1);
    pthread_mutex_unlock(&CZYTELNIK2);
}
