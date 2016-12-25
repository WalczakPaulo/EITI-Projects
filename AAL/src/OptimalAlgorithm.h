//
// Created by Paul on 2016-12-25.
//

#ifndef AAL_OPTIMALALGORITHM_H
#define AAL_OPTIMALALGORITHM_H


class OptimalAlgorithm {
public:
    OptimalAlgorithm();
    ~OptimalAlgorithm();
    void calculateSolution(int tab[], int size);
private:
    int array[1024];
    int onesArray[1024];
    int pairsArray[1024];
    int arrayOfIndices[1024];


};


#endif //AAL_OPTIMALALGORITHM_H
