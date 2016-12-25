#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "QuickSorter.h"
#include "Menu.h"
using namespace std;

int main() {
    int tab[10] = {0,2,3,4,5,3,2,1,2,7};
    int arrayOfIndices[]={0,1,2,3,4,5,6,7,8,9};
    QuickSorter quicksorter;
    quicksorter = QuickSorter();
    quicksorter.sort(tab, 0, 10, arrayOfIndices);
    for(int counter = 0; 10 > counter; counter++)
        cout << tab[counter] << endl;

    Menu *menu;
    menu = new Menu();
    menu->showMenu();
    return 0;
}