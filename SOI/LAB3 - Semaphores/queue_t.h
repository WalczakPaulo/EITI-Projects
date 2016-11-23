//
// Created by kamil on 19.11.16.
//
#ifndef SOI3_QUEUE_T_H
#define SOI3_QUEUE_T_H

#include <queue>
#include <pthread.h>
#include <semaphore.h>

class queue_t
{
    std::queue<char> q;
    int buffer_state;
    bool czyCzytelnik1Czytal;
    bool czyCzytelnik2Czytal;
    sem_t PELNY;
    sem_t PUSTY;
    pthread_mutex_t CZYTELNIK1;
    pthread_mutex_t CZYTELNIK2;
    pthread_mutex_t KSIAZKA_PRZECZYTANA1;
    pthread_mutex_t KSIAZKA_PRZECZYTANA2;
    pthread_mutex_t KTOS_PRZECZYTAL;
public:
    queue_t();
    ~queue_t();
    void push(char element);
    void pop();
    void read_element1();
    void read_element2();
};

#endif //SOI3_QUEUE_T_H
