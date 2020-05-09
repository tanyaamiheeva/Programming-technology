//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST_F(LeapTestCase, CorrectYear)
{
    ASSERT_THROW(IsLeap(-200), std::invalid_argument);
}

TEST_F(LeapTestCase, FirstTest)
{
    ASSERT_TRUE(IsLeap(1200));
}

TEST_F(LeapTestCase, SecondTest)
{
    ASSERT_FALSE(IsLeap(1300));
}

TEST_F(LeapTestCase, ThirdTest)
{
    ASSERT_TRUE(IsLeap(1204));
}

TEST_F(LeapTestCase, FourthTest)
{
    ASSERT_FALSE(IsLeap(1203));
}

