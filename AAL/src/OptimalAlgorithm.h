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
    int calculateSimple(int tab[], int size);
    int calculateSolution(int tab[], int size, vector<Combinations*> &sidesCombinations);
private:
    int array[102400];
    int onesArray[102400];
    int pairsArray[102400];
    int arrayOfIndices[102400];
    int whichSticks[102400][1024];
    int pairsForPrint[102400][1024];

};


#endif //AAL_OPTIMALALGORITHM_H
