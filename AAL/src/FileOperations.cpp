//
// Created by Paul on 2017-01-06.
//

#include "FileOperations.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<sstream>
using namespace std;

FileOperations::FileOperations(string brute, string optimal, string input) {
    setBruteforceFile(brute);
    setOptimalAlgorithmFile(optimal);
    setInputFile(input);
}



void FileOperations::writeBruteforceTime(int size, double runningTime) {
    ofstream file;
    file.open(getBruteforceFile(),fstream::app);
    file << "\nThe Running time was: " << runningTime << " for the input size of " << size;
    file.close();

}

void FileOperations::writeOptimalAlgorithmTime(int size, double runningTime) {
    ofstream file;
    file.open(getOptimalAlgorithmFile(),fstream::app);
    file << "\nThe Running time was: " << runningTime << " for the input size of " << size;
    file.close();
}

void FileOperations::setBruteforceFile(string file) {
    this->bruteforceFile = file;
}

void FileOperations::setOptimalAlgorithmFile(string file) {
    this->optimalAlgorithmFile = file;
}

void FileOperations::setInputFile(string file) {
    this->inputFile = file;
}

string FileOperations::getBruteforceFile() {
    return bruteforceFile;
}

string FileOperations::getOptimalAlgorithmFile() {
    return optimalAlgorithmFile;
}

string FileOperations::getInputFile() {
    return inputFile;
}

int FileOperations::loadDataFromFile(int *array) {
    int i = 0;
    int sizeOfInput;

    ifstream infile;
    infile.open(inputFile);
    if (infile.good())
        cout<<"Success opening file"<< endl;
    else {
        cout << "Error while opening file"<< endl;
        exit(1);
    }
    std::string line;

    while (std::getline(infile, line))
    {   int n;
        std::istringstream iss(line);
        while (iss >> n)
        {
            if ( i == 0)
                sizeOfInput = n;
            else
                array[i-1] = n;

            i++;
        }

    }

    cout << "Data read successfully" << endl;
    return sizeOfInput;
}
