//
// Created by Paul on 2016-11-19.
//

#include "Squares.h"


using namespace std;

Squares::Squares() {

    numberOfSquares = 0;
    vectorOfSquares =  new std::vector<Square>();
}

void Squares::addNewSquare(Square newSquare){

    vectorOfSquares->push_back(newSquare);
    numberOfSquares++;

}