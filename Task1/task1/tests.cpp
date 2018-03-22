#include <cstddef>
#include "pg_list.h"
#include "task1.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>


// Task1:
// intercalate with L'.' a reversed generic list-like structure.
/* 
   Haskell
   task1 :: Traversable t => String -> t String -> String
   task1 =  intercalate "." . reverse
*/


#include <limits.h>

#include "gtest/gtest.h"
#include "task1.hpp"

namespace {

    class MyFixture : public testing::Test {
    protected:  // Make the members protected s.t. they can be accessed from sub-classes.


        // optional: SetUp(). will be called before each test is run. 
        virtual void SetUp(){
            l_ = list_cons(*mkIdent(L"MyTable"), NIL);
            l_ = list_cons(*mkIdent(L"MyModule"), &l_);
            l_ = list_cons(*mkIdent(L"MyApp"), &l_);
        }

        // optional:  TearDown(). will be called after each test is run.
        virtual void TearDown() {
            // TODO cleanup l_
        }

        // Declare the variables your tests want to use.
        List l_;
        std::vector<std::string> x_ = { "foo", "bar", "baz" };
        std::vector<std::wstring> wx_ = { L"föoo", L"bar", L"baz" };
        std::string  delim_ = std::string(".");
        std::wstring wdelim_ = std::wstring(L".");

    };


    TEST_F(MyFixture, test_fixture) {

        ASSERT_EQ(list_length(NULL), 0);
        ASSERT_EQ(list_length(&l_), l_.length);

        std::cout << "len: " << list_length(&l_) << std::endl;
        list_traverse(l_);

    }
  
    TEST_F(MyFixture, task1_v1) {

        auto y = task1_v1(x_, delim_);     std::cout << "y is " << y << std::endl;
        auto z = task1_v1(wx_, wdelim_);   std::wcout << "z is " << z << std::endl;

        ASSERT_STREQ(y.c_str(), "baz.bar.foo");
        ASSERT_STREQ(z.c_str(), L"baz.bar.föoo");

    }

#ifdef HAS_CPP_RANGES
    TEST_F(MyFixture, task1_v2) {
        auto y = task1_v2(x_, delim_);     std::cout << "y is " << y << std::endl;
        auto z = task1_v2(wx_, wdelim_);   std::wcout << "z is " << z << std::endl;

        ASSERT_STREQ(y.c_str(), "baz.bar.foo");
        ASSERT_STREQ(z.c_str(), L"baz.bar.föoo");
    }
#endif

    TEST_F(MyFixture, list_reverse_concat_v1) {

        auto rc = list_reverse_concat_v1(l_);    std::wcout << "reverse is " << rc << std::endl;
        ASSERT_STREQ(rc.c_str(), L"MyTable.MyModule.MyApp");
    }

}
