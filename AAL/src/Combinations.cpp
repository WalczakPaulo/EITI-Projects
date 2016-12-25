//
// Created by Paul on 2016-12-23.
//
#include<iostream>
#include "Combinations.h"

using namespace std;

Combinations::Combinations() {
    setSides(0,0,0,0,0,0);
}

Combinations::Combinations(int a , int b , int c , int d , int e , int f) {
    setSides(a,b,c,d,e,f);
}

void Combinations::setSides(int a , int b , int c , int d , int e , int f) {
    sidesIndices[0] = a;
    sidesIndices[1] = b;
    sidesIndices[2] = c;
    sidesIndices[3] = d;
    sidesIndices[4] = e;
    sidesIndices[5] = f;
}

void Combinations::printSides() {
    for(int i = 0; i < 6 ; i++)
        cout << i << ". " <<  sidesIndices[i] << endl;
    cout << endl;
}