//
// Created by Paul on 2016-12-25.
//
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <chrono>
#include "Menu.h"
#include "Bruteforce.h"
#include "OptimalAlgorithm.h"
using namespace std;



Menu::Menu(): arrayOfSticks {0} , howManySticks(0), howManyCombinations(0), timeExecution(0), whichAlgorithmWasUsed(0)   {
    sidesCombinations = new vector <Combinations*>();
    sidesCombinations->reserve(10000000);
    fileOperator = new FileOperations("D:\\Users\\Paul\\ClionProjects\\AAL\\bruteforceTime.txt", "D:\\Users\\Paul\\ClionProjects\\AAL\\optimalAlgorithmTime.txt", "D:\\Users\\Paul\\ClionProjects\\AAL\\dataInput.txt");
}

Menu::~Menu() {
    delete(fileOperator);
    delete(sidesCombinations);
}
void Menu::showMenu(){
    system("CLS");
    cout << " ___________________ Analysis of Algorithms ___________________" << endl;
    cout << "1. Show project info. " << endl;
    cout << "2. Load data from file. " << endl;
    cout << "3. Type data by yourself. " << endl;
    cout << "4. Use bruteforce algorithm. " << endl;
    cout << "5. Use optimized algorithm. " << endl;
    cout << "6. Generate Data, measure time and present the job. " << endl;
    cout << "7. Show data. " << endl;
    cout << "8. Set input file" << endl;
    cout << "9. Securely finish the program. \n" << endl;


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
            presentJob();
            cleanTheMess();
            break;
        case 5:
            useOptimalAlgorithm();
            presentJob();
            cleanTheMess();
            showMenu();
            break;
        case 6:
            fullEngineExecution(); // generate data, measure time and show the job.
            showMenu();
            break;
        case 7:
            showData();
            break;
        case 8:
            fileOperator->createInputFile();
        case 9:
            exitProgram();
            break;
        default:
            showMenu();
    }

}

int Menu::exitProgram(){

    return 0; // bye bye

}

void Menu::presentJob() {
    char answer;
    cout << "Do you want to see the results ? (y/n)" << endl;
    cin >> answer;
    if ( answer == 'y' ) {
            printSolutions();
    }
    else ;
    cin.ignore();
    waitForAction();

}

void Menu::fullEngineExecution(){
    long long ans1[4] = {};
    long long ans2[4] = {};
    howManySticks = 100000;
    generateRandomData();
    for(int i = 0 ; i < 20; i++ ) {
        howManySticks = i * 5000;
        useSimpleOptimal();
        //ans1[i%20] = howManyCombinations;
        //useSimpleOptimal();
        //ans2[i%20] = howManyCombinations;
        //if (ans1[i%20]!=ans2[i%20])
         //   cout << " okejjj" << endl;
        //    presentJob();
        cleanTheMess();
    }
}

void Menu::generateRandomData() {

    for(int i = 0; i < howManySticks; i++) {
        arrayOfSticks[i] = rand()%200;
        while(arrayOfSticks[i]==0)
            arrayOfSticks[i] = rand()%200;
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

void Menu::cleanTheMess(){
    cout << "start cleaning" << endl;
    cout << sidesCombinations->max_size() << endl;
    cout << sidesCombinations->size() << endl;

    for (std::vector< Combinations *>::iterator it = sidesCombinations->begin() ; it != sidesCombinations->end(); ++it)
    {
        delete (*it);
    }
    cout << "deleted" << endl;
    sidesCombinations->clear();
    cout << sidesCombinations->size() << endl;
    cout << "End of cleaning" << endl;
}

void Menu::useBruteforce() {

    Bruteforce *bruteforce =new Bruteforce();
    auto start = std::chrono::high_resolution_clock::now();
    howManyCombinations = bruteforce->calculateBruteforce(arrayOfSticks,howManySticks, *sidesCombinations);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    double timeExecution = microseconds/1000;
    whichAlgorithmWasUsed = 0;
    fileOperator->writeBruteforceTime(howManySticks, timeExecution);
    fileOperator->writeRawData(howManySticks, timeExecution);
    delete(bruteforce);
}

void Menu::useSimpleOptimal() {
    OptimalAlgorithm *optimalAlgorithm = new OptimalAlgorithm();
    auto start = std::chrono::high_resolution_clock::now();
    howManyCombinations = optimalAlgorithm->calculateSimple(arrayOfSticks,howManySticks);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    double timeExecution = microseconds/1000;
    whichAlgorithmWasUsed = 1;
    fileOperator->writeOptimalAlgorithmTime(howManySticks, timeExecution);
    fileOperator->writeRawData(howManySticks,timeExecution);
    delete(optimalAlgorithm);
}

void Menu::useOptimalAlgorithm() {

    OptimalAlgorithm *optimalAlgorithm = new OptimalAlgorithm();
    auto start = std::chrono::high_resolution_clock::now();
    howManyCombinations = optimalAlgorithm->calculateSolution(arrayOfSticks,howManySticks, *sidesCombinations);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    double timeExecution = microseconds/1000;
    whichAlgorithmWasUsed = 1;
    fileOperator->writeOptimalAlgorithmTime(howManySticks, timeExecution);
    fileOperator->writeRawData(howManySticks,timeExecution);
    delete(optimalAlgorithm);

}

void Menu::waitForAction(){
    getchar();
}



void Menu::printSolutions() {


    if (howManyCombinations != 0){
        cout << "And these are: " << endl;
        int sizeOfVec = sidesCombinations->size();
        if (whichAlgorithmWasUsed == 0)
            for( int i = 0; i < sizeOfVec; i++)
                sidesCombinations->at(i)->printSides(arrayOfSticks);
        else
            for( int i = 0; i < sizeOfVec; i++)
                sidesCombinations->at(i)->printSidesSimply();

    }

    cout << "There were found " << howManyCombinations << " combinations" << endl;
    showExecutionTime();
}

void Menu::showExecutionTime(){
    cout << "Execution of program took: " << timeExecution << " ms" << endl;
}