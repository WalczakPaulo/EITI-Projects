//
// Created by Paul on 2016-12-25.
//

#ifndef AAL_MENU_H
#define AAL_MENU_H
#include "FileOperations.h"
#include "Combinations.h"
#include <vector>
class Menu {
public:
    Menu();
    ~Menu();
    void showMenu();
    void typeChoice();
    void showProjectInfo();
    void loadDataFromFile();
    void showData();
    void typeData();
    void useBruteforce();
    void useOptimalAlgorithm();
    void waitForAction();
    void printSolutions();
    int exitProgram();
    void fullEngineExecution();
    void generateRandomData();
    void showExecutionTime();
    void cleanTheMess();
    void presentJob();
private:
    int arrayOfSticks[1024];
    int howManySticks;
    FileOperations *fileOperator;
    vector <Combinations*> *sidesCombinations;
    int howManyCombinations;
    double timeExecution;
    bool whichAlgorithmWasUsed;
};


#endif //AAL_MENU_H
