//
// Created by Paul on 2016-11-19.
//

#ifndef AAL_SQUARE_H
#define AAL_SQUARE_H
#define NUMBER_OF_SIDES 6

class Square {
    Square(int newSquare[NUMBER_OF_SIDES][1]);

    void copyArray(int newSquare[NUMBER_OF_SIDES][1]);

    int lengthsAndIndicesOfSides[NUMBER_OF_SIDES][1];

};


#endif //AAL_SQUARE_H
