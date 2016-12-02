//
// Created by kamil on 19.11.16.
//
#ifndef SOI3_QUEUE_T_H
#define SOI3_QUEUE_T_H

#include <queue>
#include <pthread.h>
#include <semaphore.h>
#include "Monitors.h"

class queue_t : public Monitor, public ReadMonitor
{
    std::queue<char> q;
    int buffer_state;
    int readersCounter;
    bool czyCzytelnik1Czytal;
    bool czyCzytelnik2Czytal;
    Condition PUSTY, PELNY, KTOS_PRZECZYTAL, MOZNA_CZYTAC1, MOZNA_CZYTAC2;
    
public:
    queue_t();
    ~queue_t();
    void push(char element);
    void pop();
    void read_element1();
    void read_element2();
};

#endif //SOI3_QUEUE_T_H
