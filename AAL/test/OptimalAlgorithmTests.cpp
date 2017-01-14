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

TEST_F(OptimalAlgorithmTest, sixElementsWithoutAnswer) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int sixElements[] = {1,2,3,4,5,6};
    int response = optimal.calculateSolution(sixElements,6, *sidesCombinations);
    ASSERT_EQ(response, 0);
}

TEST_F(OptimalAlgorithmTest, sixElementsWithAnswer1) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int sixElements[] = {1,1,5,5,6,6};
    int response = optimal.calculateSolution(sixElements,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

TEST_F(OptimalAlgorithmTest, sixElementsWithAnswer2) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int sixElements[] = {1,2,3,6,6,6};
    int response = optimal.calculateSolution(sixElements,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

TEST_F(OptimalAlgorithmTest, bigSetWithoutAnswer) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int bigSet[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int response = optimal.calculateSolution(bigSet,20, *sidesCombinations);
    ASSERT_EQ(response, 0);
}

/*
 *  @tripletTestCases
 */

TEST_F(OptimalAlgorithmTest, tripletTestCase1) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {2,2,2,6,6,6};
    int response = optimal.calculateSolution(duplicateSet,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

TEST_F(OptimalAlgorithmTest, tripletTestCase2) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,3,3,7,7,7};
    int response = optimal.calculateSolution(duplicateSet,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

TEST_F(OptimalAlgorithmTest, tripletSituation1){
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,2,2,3,6,6,6};
    int response = optimal.calculateSolution(duplicateSet,7, *sidesCombinations);
    ASSERT_EQ(response, 2);
}


TEST_F(OptimalAlgorithmTest, tripletSituation2) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,1,2,2,3,6,6,6};
    int response = optimal.calculateSolution(duplicateSet,8, *sidesCombinations);
    ASSERT_EQ(response, 4);
}


TEST_F(OptimalAlgorithmTest, tripletSituation3) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,2,3,6,6,6,6};
    int response = optimal.calculateSolution(duplicateSet,7, *sidesCombinations);
    ASSERT_EQ(response, 4);
}

/*
 * @duplicateTestCases
 */

TEST_F(OptimalAlgorithmTest, duplicateTestCase1) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,5,1,5,6,6,6};
    int response = optimal.calculateSolution(duplicateSet,7, *sidesCombinations);
    ASSERT_EQ(response, 3);
}

TEST_F(OptimalAlgorithmTest, duplicateTestCase2){
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {3,3,3,3,6,6};
    int response = optimal.calculateSolution(duplicateSet,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}



TEST_F(OptimalAlgorithmTest, duplicateTestCase3) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,5,3,3,6,6};
    int response = optimal.calculateSolution(duplicateSet,6 ,*sidesCombinations);
    ASSERT_EQ(response, 1);
}


TEST_F(OptimalAlgorithmTest, duplicateTestCase4) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,6,3,4,7,7};
    int response = optimal.calculateSolution(duplicateSet,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

/*
 * @notSortedSet
 */



TEST_F(OptimalAlgorithmTest, unsortedTestCase) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {6,6,6,3,1,2};
    int response = optimal.calculateSolution(duplicateSet,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

/*
 * both duplicate and triplet situation
 */

TEST_F(OptimalAlgorithmTest, bothDuplicateAndTriplet) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,5,1,5,2,3,6,6,6};
    int response = optimal.calculateSolution(duplicateSet,9, *sidesCombinations);
    ASSERT_EQ(response, 5);
}

/*
 *  tests for simple version, fully O(n^2)
 */

TEST_F(OptimalAlgorithmTest, noElementsSimple) {

    int noElements[] = {};
    int response = optimal.calculateSimple(noElements,0);
    ASSERT_EQ(response, 0);
}

TEST_F(OptimalAlgorithmTest, lessThanSixElementsSimple) {

    int lessThanSixElements[] = {1,2,3,4,5};
    int response = optimal.calculateSimple(lessThanSixElements,5);
    ASSERT_EQ(response, 0);
}

TEST_F(OptimalAlgorithmTest, sixElementsWithoutAnswerSimple) {
    int sixElements[] = {1,2,3,4,5,6};
    int response = optimal.calculateSimple(sixElements,6);
    ASSERT_EQ(response, 0);
}

TEST_F(OptimalAlgorithmTest, sixElementsWithAnswer1Simple) {
    int sixElements[] = {1,1,5,5,6,6};
    int response = optimal.calculateSimple(sixElements,6);
    ASSERT_EQ(response, 1);
}

TEST_F(OptimalAlgorithmTest, sixElementsWithAnswer2Simple) {
    int sixElements[] = {1,2,3,6,6,6};
    int response = optimal.calculateSimple(sixElements,6);
    ASSERT_EQ(response, 1);
}

TEST_F(OptimalAlgorithmTest, bigSetWithoutAnswerSimple) {
    int bigSet[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int response = optimal.calculateSimple(bigSet,20);
    ASSERT_EQ(response, 0);
}

/*
 *  @tripletTestCases
 */

TEST_F(OptimalAlgorithmTest, tripletTestCase1Simple) {
    int duplicateSet[] = {2,2,2,6,6,6};
    int response = optimal.calculateSimple(duplicateSet,6);
    ASSERT_EQ(response, 1);
}

TEST_F(OptimalAlgorithmTest, tripletTestCase2Simple) {
    int duplicateSet[] = {1,3,3,7,7,7};
    int response = optimal.calculateSimple(duplicateSet,6);
    ASSERT_EQ(response, 1);
}

TEST_F(OptimalAlgorithmTest, tripletSituation1Simple){
    int duplicateSet[] = {1,2,2,3,6,6,6};
    int response = optimal.calculateSimple(duplicateSet,7);
    ASSERT_EQ(response, 2);
}


TEST_F(OptimalAlgorithmTest, tripletSituation2Simple) {
    int duplicateSet[] = {1,1,2,2,3,6,6,6};
    int response = optimal.calculateSimple(duplicateSet,8);
    ASSERT_EQ(response, 4);
}


TEST_F(OptimalAlgorithmTest, tripletSituation3Simple) {
    int duplicateSet[] = {1,2,3,6,6,6,6};
    int response = optimal.calculateSimple(duplicateSet,7);
    ASSERT_EQ(response, 4);
}

/*
 * @duplicateTestCases
 */

TEST_F(OptimalAlgorithmTest, duplicateTestCase1Simple) {
    int duplicateSet[] = {1,5,1,5,6,6,6};
    int response = optimal.calculateSimple(duplicateSet,7);
    ASSERT_EQ(response, 3);
}

TEST_F(OptimalAlgorithmTest, duplicateTestCase2Simple){
    int duplicateSet[] = {3,3,3,3,6,6};
    int response = optimal.calculateSimple(duplicateSet,6);
    ASSERT_EQ(response, 1);
}



TEST_F(OptimalAlgorithmTest, duplicateTestCase3Simple) {
    int duplicateSet[] = {1,5,3,3,6,6};
    int response = optimal.calculateSimple(duplicateSet,6 );
    ASSERT_EQ(response, 1);
}


TEST_F(OptimalAlgorithmTest, duplicateTestCase4Simple) {
    int duplicateSet[] = {1,6,3,4,7,7};
    int response = optimal.calculateSimple(duplicateSet,6);
    ASSERT_EQ(response, 1);
}

/*
 * @notSortedSet
 */



TEST_F(OptimalAlgorithmTest, unsortedTestCaseSimple) {
    int duplicateSet[] = {6,6,6,3,1,2};
    int response = optimal.calculateSimple(duplicateSet,6);
    ASSERT_EQ(response, 1);
}

/*
 * both duplicate and triplet situation
 */

TEST_F(OptimalAlgorithmTest, bothDuplicateAndTripletSimple) {
    int duplicateSet[] = {1,5,1,5,2,3,6,6,6};
    int response = optimal.calculateSimple(duplicateSet,9);
    ASSERT_EQ(response, 5);
}

