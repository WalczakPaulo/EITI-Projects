//
// Created by Paul on 2016-12-25.
//
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Menu.h"
#include "Bruteforce.h"
#include "OptimalAlgorithm.h"

using namespace std;


Menu::Menu(): arrayOfSticks {0} , howManySticks(0)   {

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

    int i = 0;


        ifstream infile;
        infile.open("D:\\Users\\Paul\\ClionProjects\\AAL\\dataInput.txt");
        if (infile.good())
            cout<<"Success opening file"<< endl;
        else {
            cout << "Error while opening file"<< endl;
            exit(1);
        }
        std::string line;

        while (std::getline(infile, line))
        {
            std::istringstream iss(line);
            int n;


            while (iss >> n)
            {
                if ( i == 0)
                    howManySticks = n;
                else
                    arrayOfSticks[i-1] = n;

                i++;
            }

        }






    cout << "Data read successfully" << endl;
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
    getchar();
    showMenu();
}

void Menu::showData(){

    cout << " There are " << howManySticks << " sticks " << endl;
    cout << " The sticks are: " << endl;
    for(int i = 0; i < howManySticks; i++)
        cout << arrayOfSticks[i] << endl;

    cout << "\n Type anything" << endl;
    getchar();


    showMenu();
}

void Menu::useBruteforce() {

    Bruteforce *bruteforce =new Bruteforce();
    bruteforce->calculateBruteforce(arrayOfSticks,howManySticks);
    waitForAction();
    delete(bruteforce);
    showMenu();
}

void Menu::useOptimalAlgorithm() {

    OptimalAlgorithm *optimalAlgorithm = new OptimalAlgorithm();
    optimalAlgorithm->calculateSolution(arrayOfSticks,howManySticks);
    waitForAction();
    delete(optimalAlgorithm);
    showMenu();

}

void Menu::waitForAction(){
    getchar();
}