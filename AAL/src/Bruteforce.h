//
// Created by Paul on 2016-12-25.
//

#ifndef AAL_BRUTEFORCE_H
#define AAL_BRUTEFORCE_H
#include<vector>
#include "Combinations.h"

using namespace std;

class Bruteforce {
public:
    Bruteforce();
    int calculateBruteforce(int tab[], int size, vector<Combinations*> &sidesCombinations);
private:
    int array[3009];
    int arrOfIndices[3009];
};


#endif //AAL_BRUTEFORCE_H
