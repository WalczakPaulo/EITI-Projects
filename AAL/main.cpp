#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "QuickSorter.h"
#include "Menu.h"
using namespace std;

int main() {
    Menu *menu;
    menu = new Menu();
    menu->showMenu();
    return 0;
}