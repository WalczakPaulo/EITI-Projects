//
// Created by Aleksander on 12.11.2016.
//

#include "gtest/gtest.h"
#include "SkipList.h"


class SkipListTest : public ::testing::Test {
public:
    SkipList skipList;
};


TEST_F(SkipListTest, InsertFindDelete10000) {
    const unsigned long SIZE = 10000L;

    //insert values
    for (int i = 0; i < SIZE; i++) {
        std::ostringstream os;
        os << i;
        skipList.insert(i, os.str());
    }

    //find and delete
    for (int i = 0; i < SIZE; i++) {
        std::ostringstream os;
        os << i;
        ASSERT_EQ(*(skipList.find(i)), os.str());
        ASSERT_TRUE(skipList.erase(i));
        ASSERT_EQ(skipList.find(i), nullptr);
    }
}


TEST_F(SkipListTest, EmptyList) {
    ASSERT_EQ(skipList.find(10), nullptr);
    ASSERT_FALSE(skipList.erase(10));
}


TEST_F(SkipListTest, InsertFindDelete1) {
    const std::string value = "v";
    const int key = 10;

    skipList.insert(key, value);
    ASSERT_EQ(*(skipList.find(key)), value);
    ASSERT_TRUE(skipList.erase(key));
    ASSERT_EQ(skipList.find(key), nullptr);
}
