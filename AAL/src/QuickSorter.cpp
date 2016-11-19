//
// Created by Paul on 2016-10-26.
//
#include <iostream>
#include "QuickSorter.h"

QuickSorter::QuickSorter()
{

}

QuickSorter::~QuickSorter()
{

}

void QuickSorter::sort(int arr[], int start, int end )
{
      //  if (arr==NULL)
       //     return ;
        if( start < end)
        {
            int pIndex;
            pIndex = partition(arr, start, end);
            sort(arr, start, pIndex - 1);
            sort(arr, pIndex + 1 , end);

        }

        return;

}

int QuickSorter::partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int pIndex = start ;
    int counter = start;
    while( counter < end )
    {
        if( arr[counter] < pivot)
        {
            swap(arr[counter], arr[pIndex]);
            pIndex++;
        }

        counter++;
    }

    swap(arr[pIndex], arr[end]);
    return pIndex;
}

void QuickSorter::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y= temp;
}