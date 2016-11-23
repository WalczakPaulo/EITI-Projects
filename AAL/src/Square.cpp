//
// Created by Paul on 2016-11-19.
//

#include "Square.h"


Square::Square(int newSquare[NUMBER_OF_SIDES][1]){

    copyArray(newSquare);

}

void Square::copyArray(int newSquare[NUMBER_OF_SIDES][1]){

    for(int i = 0; i < NUMBER_OF_SIDES; i++)
        lengthsAndIndicesOfSides[i][0] = newSquare[i][0];

}