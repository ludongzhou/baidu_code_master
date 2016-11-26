
#include <common.h>
#include <gtest/gtest.h>
	
	
int main(int argc, char **argv)
{
 	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
/**
 * @brief 
**/
class test_Common_Common_suite : public ::testing::Test{
    protected:
        test_Common_Common_suite(){};
        virtual ~test_Common_Common_suite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_Common_Common_suite, *)
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_Common_Common_suite, *)
        };
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(test_Common_Common_suite, case_name1)
{
	//TODO
}
 
/**
 * @brief 
**/
class test_Common__s_split_suite : public ::testing::Test{
    protected:
        test_Common__s_split_suite(){};
        virtual ~test_Common__s_split_suite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_Common__s_split_suite, *)
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_Common__s_split_suite, *)
        };
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(test_Common__s_split_suite, case_name1)
{
	//TODO
}
 
