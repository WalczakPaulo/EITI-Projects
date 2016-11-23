//
// Created by Paul on 2016-11-19.
//

#ifndef AAL_SQUARES_H
#define AAL_SQUARES_H


#include "Square.h"
#include<vector>

class Squares {
    Squares();
    void addNewSquare(Square);
    int numberOfSquares;
    std::vector <Square> *vectorOfSquares;
};


#endif //AAL_SQUARES_H
