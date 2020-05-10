//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <boost/filesystem/operations.hpp>
#include <fstream>

using boost::filesystem::current_path;
using boost::filesystem::create_directory;
using boost::filesystem::remove_all;

class TreeTestCase : public ::testing::Test {
    public:
        void SetUp();
        void TearDown();
        std::string current_path = "";
        std::string path_for_test = "";
};

void TreeTestCase::SetUp()
{
    TreeTestCase::current_path = boost::filesystem::current_path().string();
    TreeTestCase::path_for_test = TreeTestCase::current_path + "/testing";
    create_directory(TreeTestCase::path_for_test);
    std::ofstream file(TreeTestCase::path_for_test + "/test.txt");
    file << "still testing"; file.close();
}

void TreeTestCase::TearDown()
{
    remove_all(path_for_test);
}

TEST_F(TreeTestCase, Equality)
{
    ASSERT_EQ(GetTree(TreeTestCase::path_for_test, true), GetTree(TreeTestCase::path_for_test, true));
}


TEST_F(TreeTestCase, NonExistingPath)
{
    ASSERT_THROW(GetTree("whereami", true), std::invalid_argument);
}

TEST_F(TreeTestCase, PathAsDirectory)
{
    ASSERT_THROW(GetTree(TreeTestCase::path_for_test + "/test.txt", true), std::invalid_argument);
}

TEST_F(TreeTestCase, IsNoDirectory)
{
    ASSERT_NO_THROW(GetTree(TreeTestCase::path_for_test, false));
}

TEST_F(TreeTestCase, IsDirectory)
{
    ASSERT_NO_THROW(GetTree(TreeTestCase::path_for_test, true));
}


