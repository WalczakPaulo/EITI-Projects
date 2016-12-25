//
// Created by Paul on 2016-12-23.
//

#ifndef BRUTEFORCE_AAL_COMBINATIONS_H
#define BRUTEFORCE_AAL_COMBINATIONS_H


class Combinations {
public:
    Combinations();
    Combinations(int,int,int,int,int,int, bool);
    void setSides(int, int, int, int, int, int);
    void printSides(int array[]);
private:
    int sidesIndices[6];
    bool isCombinationTriple;
};


#endif //BRUTEFORCE_AAL_COMBINATIONS_H
