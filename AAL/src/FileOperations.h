//
// Created by Paul on 2017-01-06.
//

#ifndef AAL_FILEOPERATIONS_H
#define AAL_FILEOPERATIONS_H

#include <string>
using namespace std;

class FileOperations {
public:
    FileOperations(string, string, string);
    void setBruteforceFile(string);
    void setOptimalAlgorithmFile(string);
    void setInputFile(string);
    string getBruteforceFile();
    string getOptimalAlgorithmFile();
    string getInputFile();
    void writeBruteforceTime(int,double);
    void writeRawData(int, double); // for MATLAB
    void writeOptimalAlgorithmTime(int, double);
    void createInputFile();
    int loadDataFromFile(int array[]);
private:
    string bruteforceFile;
    string optimalAlgorithmFile;
    string inputFile;
};


#endif //AAL_FILEOPERATIONS_H
