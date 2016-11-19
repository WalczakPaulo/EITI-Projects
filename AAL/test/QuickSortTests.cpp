//
// Created by Aleksander on 12.11.2016.
//

#include "gtest/gtest.h"
#include "QuickSorter.h"


class QuickSorterTest : public ::testing::Test {
public:
    QuickSorter quicksorter;
};

TEST_F(QuickSorterTest, TypicalArrayWithDuplicateValues) {

    int typicalArrayWithDuplicateValues[] = {9,9,4,4,2,0,2,3,5,6,3,5,6,10,12};
    int sameArraySorted[] = {0,2,2,3,3,4,4,5,5,6,6,9,9,10,12};
    int SIZE = 15;
    quicksorter.sort(typicalArrayWithDuplicateValues,0,15);
    for (int i = 0; i < SIZE; i++) {
        ASSERT_EQ(sameArraySorted[i], typicalArrayWithDuplicateValues[i]);
    }

}

TEST_F(QuickSorterTest, TypicalArray) {
    int typicalArray[] = {10,9,8,7,6,5,4,3,2,1};
    int typicalArraySorted[] = {1,2,3,4,5,6,7,8,9,10};
    int SIZE = 10;
    quicksorter.sort(typicalArray,0,10);
    //insert values
    for (int i = 0; i < SIZE; i++) {
        ASSERT_EQ(typicalArraySorted[i], typicalArray[i]);
    }


}


TEST_F(QuickSorterTest, OneValue) {

    int array[] ={1};
    quicksorter.sort(array,0,1);
    //insert values

        ASSERT_EQ(*array, 1);
    }


TEST_F(QuickSorterTest, EmptyValue) {

    int array[0];
    quicksorter.sort(array,0,1);
    //insert values

    ASSERT_EQ(*array, NULL);
}

