#include <iostream>

#include <gtest/gtest.h>

#include "square.hpp"

class TestFoo : public ::testing::Test
{
protected:
    void SetUp()
    {
        std::cout << "SetUp" << std::endl;
    }
    void TearDown()
    {
        std::cout << "TearDown" << std::endl;
    }
};

TEST_F(TestFoo, test_square)
{
    ASSERT_EQ(square(2), 4);
    ASSERT_EQ(square(4), 16);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

