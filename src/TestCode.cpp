#include <iostream>

#include "gtest/gtest.h"

class SampleTest : public testing::Test {
    int a = 0;
    int b = 0;
};

TEST_F(SampleTest, TestEqual){
    EXPECT_EQ(a, b);
}