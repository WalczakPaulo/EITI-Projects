//
// Created by Paul on 2016-12-25.
//
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <ctime>
#include <fstream>
#include <vector>
#include "Menu.h"
#include "Bruteforce.h"
#include "OptimalAlgorithm.h"
#include "FileOperations.h"
using namespace std;


Menu::Menu(): arrayOfSticks {0} , howManySticks(0), howManyCombinations(0)   {
    sidesCombinations = new vector <Combinations*>();
    fileOperator = new FileOperations("D:\\Users\\Paul\\ClionProjects\\AAL\\bruteforceTime.txt", "D:\\Users\\Paul\\ClionProjects\\AAL\\optimalAlgorithmTime.txt", "D:\\Users\\Paul\\ClionProjects\\AAL\\dataInput.txt");
}

Menu::~Menu(){

}

void Menu::showMenu(){

    system("CLS");
    cout << " ___________________ Analysis of Algorithms ___________________" << endl;
    cout << "1. Show project info. " << endl;
    cout << "2. Load data from file. " << endl;
    cout << "3. Type data by yourself. " << endl;
    cout << "4. Use bruteforce algorithm. " << endl;
    cout << "5. Use optimized algorithm. " << endl;
    cout << "6. Show data. \n" << endl;


    typeChoice();

}

void Menu::typeChoice(){


    cout << "Enter your choice: " << endl;
    int n = 0;
    cin >> n;
    cin.ignore();
    switch(n){
        case 1:
            showProjectInfo();
            break;
        case 2:
            loadDataFromFile();
            break;
        case 3:
            typeData();
            break;
        case 4:
            useBruteforce();
            break;
        case 5:
            useOptimalAlgorithm();
            break;
        case 6:
            showData();
            break;
        default:
            showMenu();
    }

}

void Menu::showProjectInfo(){

    char n;
    system("CLS");
    cout << " We have a set of N unbreakable sticks with lengths s[i], where i is (1,2,3,4,5...,N). Find an algorithm which will evaluate" <<
           " on how many ways we can build a square using 6 of given sticks, and will show which should one use. " << endl;
    cout << "\n Type anything" << endl;

    getchar();

    showMenu();
}

void Menu::loadDataFromFile(){

    howManySticks = fileOperator->loadDataFromFile(arrayOfSticks);
    getchar();
    showMenu();

}

void Menu::typeData(){

    cout << "Type howManySticks of set of sticks:  " << endl;
    cin >> howManySticks;
    cout << "Now type each stick's length: " << endl;
    for(int i = 0 ; i < howManySticks ; i++)
        cin >> arrayOfSticks[i];
    cout << "Thanks. Press anything to return to menu..." << endl;
    cin.ignore();
    waitForAction();
    showMenu();
}

void Menu::showData(){

    cout << " There are " << howManySticks << " sticks " << endl;
    cout << " The sticks are: " << endl;
    for(int i = 0; i < howManySticks; i++)
        cout << arrayOfSticks[i] << endl;

    cout << "\n Type anything" << endl;
    waitForAction();


    showMenu();
}

void Menu::useBruteforce() {

    Bruteforce *bruteforce =new Bruteforce();
    clock_t begin = clock();
    howManyCombinations = bruteforce->calculateBruteforce(arrayOfSticks,howManySticks, *sidesCombinations);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    fileOperator->writeBruteforceTime(howManySticks, elapsed_secs);
    printSolutions();
    waitForAction();
    delete(bruteforce);
    showMenu();
}

void Menu::useOptimalAlgorithm() {

    OptimalAlgorithm *optimalAlgorithm = new OptimalAlgorithm();
    clock_t begin = clock();
    howManyCombinations = optimalAlgorithm->calculateSolution(arrayOfSticks,howManySticks, *sidesCombinations);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    fileOperator->writeOptimalAlgorithmTime(howManySticks, elapsed_secs);
    printSolutionsForOptimal();
    waitForAction();
    delete(optimalAlgorithm);
    showMenu();

}

void Menu::waitForAction(){
    getchar();
}

void Menu::printSolutionsForOptimal() {

    cout << "There were found " << howManyCombinations << " combinations" << endl;
    if (howManyCombinations != 0){
        cout << "And these are: " << endl;
        int sizeOfVec = sidesCombinations->size();
        for( int i = 0; i < sizeOfVec; i++)
            sidesCombinations->at(i)->printSidesSimply();
    }


}

void Menu::printSolutions() {

    cout << "There were found " << howManyCombinations << " combinations" << endl;
    if (howManyCombinations != 0){
        cout << "And these are: " << endl;
        int sizeOfVec = sidesCombinations->size();
        for( int i = 0; i < sizeOfVec; i++)
            sidesCombinations->at(i)->printSides(arrayOfSticks);
    }


}