//
// Created by Paul on 2016-12-23.
//

#ifndef BRUTEFORCE_AAL_COMBINATIONS_H
#define BRUTEFORCE_AAL_COMBINATIONS_H


class Combinations {
public:
    Combinations();
    Combinations(int,int,int,int,int,int);
    void setSides(int, int, int, int, int, int);
    void printSides();
    int sidesIndices[6];
};


#endif //BRUTEFORCE_AAL_COMBINATIONS_H
