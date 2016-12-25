//
// Created by Paul on 2016-10-26.
//

#ifndef AAL_QUICKSORTER_H
#define AAL_QUICKSORTER_H


class QuickSorter {

public:
    QuickSorter();
    QuickSorter(int);
    ~QuickSorter();
    void sort(int tab[], int left, int right, int[]);
    void swap(int &src, int &dest);
    int partition(int arr[], int start, int end, int[]);
    void fillArrayOfIndices();


};


#endif //AAL_QUICKSORTER_H
