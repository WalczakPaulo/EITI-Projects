//
// Created by Paul on 2016-12-25.
//

#ifndef AAL_MENU_H
#define AAL_MENU_H


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
private:
    int arrayOfSticks[1024];
    int howManySticks;
};


#endif //AAL_MENU_H
