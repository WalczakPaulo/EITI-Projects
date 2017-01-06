//
// Created by Paul on 2016-12-27.
//


#include "gtest/gtest.h"
#include "Bruteforce.h"
#include "Combinations.h"


class BruteforceTest : public ::testing::Test {
public:
    Bruteforce bruteforce;
};


TEST_F(BruteforceTest, noElements) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int noElements[] = {};
    int response = bruteforce.calculateBruteforce(noElements,0, *sidesCombinations);
    ASSERT_EQ(response, 0);
}

TEST_F(BruteforceTest, lessThanSixElements) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int lessThanSixElements[] = {1,2,3,4,5};
    int response = bruteforce.calculateBruteforce(lessThanSixElements,5, *sidesCombinations);
    ASSERT_EQ(response, 0);
}

TEST_F(BruteforceTest, sixElementsWithoutAnswer) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int sixElements[] = {1,2,3,4,5,6};
    int response = bruteforce.calculateBruteforce(sixElements,6, *sidesCombinations);
    ASSERT_EQ(response, 0);
}

TEST_F(BruteforceTest, sixElementsWithAnswer1) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int sixElements[] = {1,1,5,5,6,6};
    int response = bruteforce.calculateBruteforce(sixElements,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

TEST_F(BruteforceTest, sixElementsWithAnswer2) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int sixElements[] = {1,2,3,6,6,6};
    int response = bruteforce.calculateBruteforce(sixElements,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

TEST_F(BruteforceTest, bigSetWithoutAnswer) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int bigSet[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int response = bruteforce.calculateBruteforce(bigSet,20, *sidesCombinations);
    ASSERT_EQ(response, 0);
}

/*
 *  @tripletTestCases
 */

TEST_F(BruteforceTest, tripletTestCase1) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {2,2,2,6,6,6};
    int response = bruteforce.calculateBruteforce(duplicateSet,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

TEST_F(BruteforceTest, tripletTestCase2) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,3,3,7,7,7};
    int response = bruteforce.calculateBruteforce(duplicateSet,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

TEST_F(BruteforceTest, tripletSituation1) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,2,2,3,6,6,6};
    int response = bruteforce.calculateBruteforce(duplicateSet,7, *sidesCombinations);
    ASSERT_EQ(response, 2);
}


TEST_F(BruteforceTest, tripletSituation2) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,1,2,2,3,6,6,6};
    int response = bruteforce.calculateBruteforce(duplicateSet,8, *sidesCombinations);
    ASSERT_EQ(response, 4);
}


TEST_F(BruteforceTest, tripletSituation3) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,2,3,6,6,6,6};
    int response = bruteforce.calculateBruteforce(duplicateSet,7, *sidesCombinations);
    ASSERT_EQ(response, 4);
}

/*
 * @duplicateTestCases
 */

TEST_F(BruteforceTest, duplicateTestCase1) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,5,1,5,6,6,6};
    int response = bruteforce.calculateBruteforce(duplicateSet,7, *sidesCombinations);
    ASSERT_EQ(response, 3);
}

TEST_F(BruteforceTest, duplicateTestCase2) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {3,3,3,3,6,6};
    int response = bruteforce.calculateBruteforce(duplicateSet,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}



TEST_F(BruteforceTest, duplicateTestCase3) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,5,3,3,6,6};
    int response = bruteforce.calculateBruteforce(duplicateSet,6 ,*sidesCombinations);
    ASSERT_EQ(response, 1);
}


TEST_F(BruteforceTest, duplicateTestCase4) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,6,3,4,7,7};
    int response = bruteforce.calculateBruteforce(duplicateSet,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

/*
 * @notSortedSet
 */



TEST_F(BruteforceTest, unsortedTestCase) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {6,6,6,3,1,2};
    int response = bruteforce.calculateBruteforce(duplicateSet,6, *sidesCombinations);
    ASSERT_EQ(response, 1);
}

/*
 * both duplicate and triplet situation
 */

TEST_F(BruteforceTest, bothDuplicateAndTriplet) {
    vector <Combinations*> *sidesCombinations = new vector <Combinations*>();
    int duplicateSet[] = {1,5,1,5,2,3,6,6,6};
    int response = bruteforce.calculateBruteforce(duplicateSet,9, *sidesCombinations);
    ASSERT_EQ(response, 5);
}
