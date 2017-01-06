//
// Created by Paul on 2016-12-25.
//

#ifndef AAL_OPTIMALALGORITHM_H
#define AAL_OPTIMALALGORITHM_H
#include "Combinations.h"
#include <vector>

using namespace std;

class OptimalAlgorithm {
public:
    OptimalAlgorithm();
    ~OptimalAlgorithm();
    int calculateSolution(int tab[], int size, vector<Combinations*> &sidesCombinations);
private:
    int array[1024];
    int onesArray[1024];
    int pairsArray[1024];
    int arrayOfIndices[1024];
    int whichSticks[1024][1024];


};


#endif //AAL_OPTIMALALGORITHM_H
