//
// Created by Paul on 2016-12-23.
//
#include<iostream>
#include "Combinations.h"

using namespace std;

Combinations::Combinations() {
    isCombinationTriple = false;
    setSides(0,0,0,0,0,0);
}

Combinations::Combinations(int a , int b , int c , int d , int e , int f, bool isCombinationTriple) {
    setSides(a,b,c,d,e,f);
    this->isCombinationTriple = isCombinationTriple;
}

void Combinations::setSides(int a , int b , int c , int d , int e , int f) {
    sidesIndices[0] = a;
    sidesIndices[3] = b;
    sidesIndices[2] = c;
    sidesIndices[1] = d;
    sidesIndices[4] = e;
    sidesIndices[5] = f;
}

void Combinations::printSidesSimply(){

    char tab[25][20] = {0};
    for (int j = 0; j < 20; j++)
        for (int i = 0; i < 25; i++)
            tab[i][j] = ' ';

    for (int i = 0; i < 25; i++) {
        tab[i][0] = 'x';
        tab[i][19] = 'x';
    }

    for (int j = 0; j < 20; j++) {
        tab[0][j] = 'x';
        tab[24][j] = 'x';
    }


    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 25; i++)
            cout << tab[i][j];
        cout << endl;
    }

    if (isCombinationTriple) {
        cout << "1. Side" << endl;
        cout << "Length " << sidesIndices[0] << endl;
        cout << "2. Side" << endl;
        cout <<  "Length " << sidesIndices[1] << endl;
        cout << "3. Side" << endl;
        cout  <<"Length " << sidesIndices[2] << endl;
        cout << "4. Side" << endl;
        cout <<  "Length " <<sidesIndices[3] << endl;
        cout << "Length " << sidesIndices[4] << endl;
        cout << "Length " << sidesIndices[5] << endl;
    } else {
        cout << "1. Side" << endl;
        cout <<  "Length " <<sidesIndices[5] << endl;
        cout << "2. Side" << endl;
        cout << "Length " <<sidesIndices[4] << endl;
        cout << "3. Side" << endl;
        cout << "Length " <<sidesIndices[3] << endl;
        cout << "Length " <<sidesIndices[0] << endl;
        cout << "4. Side" << endl;
        cout << "Length " <<sidesIndices[2] << endl;
        cout << "Length " <<sidesIndices[1] << endl;

    }

}

void Combinations::printSides(int *array) {


    char tab[25][20] = {0};
    for (int j = 0; j < 20; j++)
        for (int i = 0; i < 25; i++)
            tab[i][j] = ' ';

        for (int i = 0; i < 25; i++) {
            tab[i][0] = 'x';
            tab[i][19] = 'x';
        }

        for (int j = 0; j < 20; j++) {
            tab[0][j] = 'x';
            tab[24][j] = 'x';
        }


        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < 25; i++)
                cout << tab[i][j];
            cout << endl;
        }

        if (isCombinationTriple) {
            cout << "1. Side" << endl;
            cout << "Index " << sidesIndices[5] << " -> " << "Length " << array[sidesIndices[5]] << endl;
            cout << "2. Side" << endl;
            cout << "Index " << sidesIndices[4] << " -> " << "Length " <<array[sidesIndices[4]] << endl;
            cout << "3. Side" << endl;
            cout << "Index " << sidesIndices[1] << " -> " <<"Length " << array[sidesIndices[1]] << endl;
            cout << "4. Side" << endl;
            cout << "Index " << sidesIndices[2] << " -> " << "Length " <<array[sidesIndices[2]] << endl;
            cout << "Index " << sidesIndices[3] << " -> " << "Length " <<array[sidesIndices[3]] << endl;
            cout << "Index " <<  sidesIndices[0] << " -> " << "Length " << array[sidesIndices[0]] << endl;


        } else {
            cout << "1. Side" << endl;
            cout << "Index " <<  sidesIndices[5] << " -> " << "Length " <<array[sidesIndices[5]] << endl;
            cout << "2. Side" << endl;
            cout << "Index " << sidesIndices[4] << " -> " << "Length " <<array[sidesIndices[4]] << endl;
            cout << "3. Side" << endl;
            cout << "Index " << sidesIndices[3] << " -> " << "Length " <<array[sidesIndices[3]] << endl;
            cout << "Index " << sidesIndices[0] << " -> " << "Length " <<array[sidesIndices[0]] << endl;
            cout << "4. Side" << endl;
            cout << "Index " << sidesIndices[2] << " -> " << "Length " <<array[sidesIndices[2]] << endl;
            cout << "Index " << sidesIndices[1] << " -> " << "Length " <<array[sidesIndices[1]] << endl;

        }

        cout << endl;
    }






