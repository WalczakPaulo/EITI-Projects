//
// Created by Paul on 2016-12-25.
//

#include "Bruteforce.h"
#include "QuickSorter.h"
#include <iostream>
#include <cstdio>

using namespace std;

Bruteforce::Bruteforce(): array{0}, b{0}, c{0}, arrOfIndices{0} {

}

void Bruteforce::calculateBruteforce(int *tab, int size) {
    QuickSorter quickSorter = QuickSorter();
    int n = size;
    for (int i=1;i<=n;i++) array[i] = tab[i-1],c[array[i]]++;

    quickSorter.sort(array,1,n-1,arrOfIndices);
    long long ans=0,D,DD;


    for (int i=1;i<=n;i++){
        for (int s=i+1;s<=n;s++)
            if (array[s]>array[s-1])
                ans+=1ll*c[array[s]]*(c[array[s]]-1)*(c[array[s]]-2)/6*b[array[s]-array[i]];
        for (int j=1;j<i;j++)
            b[array[i]+array[j]]++;
    }
    for (int i=1;i<=n;i++)
        if (array[i]!=array[i-1] && c[array[i]]>1)
        {
            DD=c[array[i]]*(c[array[i]]-1)/2;
            D=0;
            for (int j=1;array[j]*2<array[i];j++)
                if (array[j]>array[j-1]){
                    ans+=DD*c[array[j]]*(c[array[j]]-1)/2*c[array[i]-array[j]]*(c[array[i]-array[j]]-1)/2;
                    ans+=DD*D*c[array[j]]*c[array[i]-array[j]];
                    D+=c[array[j]]*c[array[i]-array[j]];
                }
            if (array[i]%2==0){
                ans+=DD*c[array[i]/2]*(c[array[i]/2]-1)*(c[array[i]/2]-2)*(c[array[i]/2]-3)/24;
                ans+=DD*D*c[array[i]/2]*(c[array[i]/2]-1)/2;
            }
        }
    cout << "The answer is: " << endl;
    cout<<ans<<endl;
    getchar();
}
