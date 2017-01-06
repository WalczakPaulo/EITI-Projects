//
// Created by Paul on 2017-01-06.
//

#include "gtest/gtest.h"
#include "OptimalAlgorithm.h"
#include "Combinations.h"
class OptimalAlgorithmTest : public ::testing::Test {
public:
    OptimalAlgorithm optimal;
};

TEST_F(OptimalAlgorithmTest, noElements) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int noElements[] = {};
    int response = optimal.calculateSolution(noElements,0, *sidesCombinations);
    ASSERT_EQ(response, 0);
}

TEST_F(OptimalAlgorithmTest, lessThanSixElements) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int lessThanSixElements[] = {1,2,3,4,5};
    int response = optimal.calculateSolution(lessThanSixElements,5, *sidesCombinations);
    ASSERT_EQ(response, 0);
}

