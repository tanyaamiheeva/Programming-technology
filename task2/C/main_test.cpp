#include "main_test.h"

TEST(tests, A_working) 
{
    EXPECT_NO_THROW(check_a());
}

TEST(tests, B_working)
{
    EXPECT_NO_THROW(check_b());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
