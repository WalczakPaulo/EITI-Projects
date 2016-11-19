//
// Created by Paul on 2016-11-19.
//

#ifndef AAL_ENGINE_H
#define AAL_ENGINE_H


/*
 * go through the array, until duplicate/triplet found. When triplet is found, do the operations in order to find three
 * elements ( less than the value of triplet) that will sum up to value of triplet.
 * When duplicate is found, try to find pairs of values that would sum up to value of duplicate.
 */

class Engine {


public:
    Engine(int size);
    void startTheEngine(int sortedArray[], int originalArray[]);
    void findForDuplicates(int indexOfElement,int howManySameValues);
    void findForTriplets(int indexOfElement,int howManySameValues);
    int sizeOfArray;


};


#endif //AAL_ENGINE_H
