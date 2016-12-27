//
// Created by Paul on 2016-12-25.
//

#include "OptimalAlgorithm.h"
#include "QuickSorter.h"
#include <iostream>
#include <cstdio>

using namespace std;

OptimalAlgorithm::OptimalAlgorithm(): array{0}, onesArray{0}, pairsArray{0}, arrayOfIndices{0} {

}

OptimalAlgorithm::~OptimalAlgorithm() {

}

void OptimalAlgorithm::calculateSolution(int *tab, int size) {

    QuickSorter quickSorter = QuickSorter();
    int n = size;
    for (int i=1;i<=n;i++) array[i] = tab[i-1], onesArray[array[i]]++;

    quickSorter.sort(array,1,n,arrayOfIndices);
    long long ans=0,D,DD;


    for (int i=1;i<=n;i++){
        for (int s=i+1;s<=n;s++)
            if (array[s]>array[s-1])
                ans+=1ll*onesArray[array[s]]*(onesArray[array[s]]-1)*(onesArray[array[s]]-2)/6*pairsArray[array[s]-array[i]];
        for (int j=1;j<i;j++)
            pairsArray[array[i]+array[j]]++;
    }
    for (int i=1;i<=n;i++)
        if (array[i]!=array[i-1] && onesArray[array[i]]>1)
        {
            DD=onesArray[array[i]]*(onesArray[array[i]]-1)/2;
            D=0;
            for (int j=1;array[j]*2<array[i];j++)
                if (array[j]>array[j-1]){
                    ans+=DD*onesArray[array[j]]*(onesArray[array[j]]-1)/2*onesArray[array[i]-array[j]]*(onesArray[array[i]-array[j]]-1)/2;
                    ans+=DD*D*onesArray[array[j]]*onesArray[array[i]-array[j]];
                    D+=onesArray[array[j]]*onesArray[array[i]-array[j]];
                }
            if (array[i]%2==0){
                ans+=DD*onesArray[array[i]/2]*(onesArray[array[i]/2]-1)*(onesArray[array[i]/2]-2)*(onesArray[array[i]/2]-3)/24;
                ans+=DD*D*onesArray[array[i]/2]*(onesArray[array[i]/2]-1)/2;
            }
        }

    cout << "There were found " << ans << " combinations" << endl;
    if (ans != 0){
        cout << "And these are: " << endl;
    }


}