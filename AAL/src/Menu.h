//
// Created by Paul on 2016-12-25.
//

#ifndef AAL_MENU_H
#define AAL_MENU_H
#include "FileOperations.h"
#include "Combinations.h"
#include "OptimalAlgorithm.h"
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
    void useOptimalAlgorithm(); // method, with using vectors as container for sides combinations
    void waitForAction();
    void printSolutions(); // for useOptimalAlgorithm method
    int exitProgram();
    void fullEngineExecution();
    void generateRandomData();
    void showExecutionTime();
    void useSimpleOptimal();
    void cleanTheMess();
    void presentJob();
    void showCombinations();
    OptimalAlgorithm *optimalAlgorithm;
private:
    int arrayOfSticks[102400];
    int howManySticks;
    FileOperations *fileOperator;
    vector <Combinations*> *sidesCombinations;
    int howManyCombinations;
    double timeExecution;
    bool whichAlgorithmWasUsed;
};


#endif //AAL_MENU_H
