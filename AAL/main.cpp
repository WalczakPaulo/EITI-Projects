#include <iostream>
#include "QuickSorter.h"

using namespace std;

int main() {
    int tab[10] = {0,2,3,4,5,3,2,1,2,7};
    QuickSorter quicksorter = QuickSorter();
    quicksorter.sort(tab, 0, 9);
    for(int counter = 0; 10 > counter; counter++)
        cout << tab[counter] << endl;
    return 0;
}