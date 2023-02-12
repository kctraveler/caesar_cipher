#include "gtest/gtest.h"
#include <string>

int add(int a, int b) {
    return a + b;
}

TEST(AdditionTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(4, 5), 9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}