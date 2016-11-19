//
// Created by Paul on 2016-11-19.
//

#include "Engine.h"

Engine::Engine(int size){
    sizeOfArray = size;
}

void Engine::startTheEngine(int *sortedArray, int *originalArray) {

    int previousValue = sortedArray[0];
    int tempCounter = 0;
    int howManySameValues = 0;
    for( int mainCounter = 4; mainCounter < sizeOfArray; mainCounter++ ){

        tempCounter = mainCounter + 1;
        if (previousValue == sortedArray[mainCounter]){
            howManySameValues++;
            while(previousValue==sortedArray[tempCounter]){
                howManySameValues++;
            }

            findForDuplicates(mainCounter,howManySameValues);
            if(tempCounter!=mainCounter+1)
                findForTriplets(mainCounter,howManySameValues);
        }

        previousValue = sortedArray[mainCounter];
        howManySameValues = 0;
    }

}

void Engine::findForDuplicates(int indexOfElement,int howManySameValues){

}

void Engine::findForTriplets(int indexOfElement,int howManySameValues){

}