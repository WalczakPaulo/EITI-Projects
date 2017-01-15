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
    file << "\nThe Running time was: " << runningTime << " ms for the input size of " << size;
    file.close();

}

void FileOperations::writeOptimalAlgorithmTime(int size, double runningTime) {
    ofstream file;
    file.open(getOptimalAlgorithmFile(),fstream::app);
    file << "\nThe Running time was: " << runningTime << " ms for the input size of " << size;
    file.close();
}

void FileOperations::writeRawData(int size, double runningTime){
    ofstream file;
    file.open("D:\\Users\\Paul\\ClionProjects\\AAL\\rawRunningTimeData.txt" ,fstream::app);
    file  << runningTime << "\n";
    file << size << "\n";
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

void FileOperations::setRawRunningTimeFile(string file){
    this->rawRunningTimeFile = file;
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

void FileOperations::createInputFile() {
    string inputFile;
    cout << "Enter your string for input file. " << endl;
    cin >> inputFile;
    ofstream file;
    setInputFile(inputFile);
    file.open(inputFile,fstream::app);
    file.close();
}

void FileOperations::createRawRunningTimeFile() {
    string rawRunningTimeFile;
    cout << "Enter your string for raw Running Time file. " << endl;
    cin >> rawRunningTimeFile;
    ofstream file;
    setRawRunningTimeFile(rawRunningTimeFile);
    file.open(rawRunningTimeFile,fstream::app);
    file.close();
}

void FileOperations::createOptimalAlgorithmFile() {
    string optimalFile;
    cout << "Enter your string for optimal Algorithm file. " << endl;
    cin >> optimalFile;
    ofstream file;
    setOptimalAlgorithmFile(optimalFile);
    file.open(optimalFile,fstream::app);
    file.close();
}

void FileOperations::createBruteforceFile() {
    string bruteforceFile;
    cout << "Enter your string for bruteforce time file. " << endl;
    cin >> bruteforceFile;
    ofstream file;
    setBruteforceFile(bruteforceFile);
    file.open(bruteforceFile,fstream::app);
    file.close();
}