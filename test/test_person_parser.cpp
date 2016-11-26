
#include <person_parser.h>
#include <common_parser.h>
#include <gtest/gtest.h>
	
	
int main(int argc, char **argv)
{
 	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
 
/**
 * @brief 
**/
class test_PersonParser_to_string_suite : public ::testing::Test{
    protected:
        test_PersonParser_to_string_suite(){};
        virtual ~test_PersonParser_to_string_suite(){};
        virtual void SetUp() {
            testobj = new wp::PersonParser();
            //Called befor every TEST_F(test_PersonParser_to_string_suite, *)
        };
        virtual void TearDown() {
            delete testobj;
            //Called after every TEST_F(test_PersonParser_to_string_suite, *)
        };
        wp::PersonParser* testobj;
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(test_PersonParser_to_string_suite, case_name1)
{
	//TODO
    ASSERT_EQ(1, testobj->parse("zhangsan|22"));
    std::string result = testobj->to_string();
    ASSERT_STREQ("Name: zhangsan; Age: 22.", result.c_str());
}
 
/**
 * @brief 
**/
class test_PersonParser_parse_suite : public ::testing::Test{
    protected:
        test_PersonParser_parse_suite(){};
        virtual ~test_PersonParser_parse_suite(){};
        virtual void SetUp() {
            testobj = new wp::PersonParser();
            //Called befor every TEST_F(test_PersonParser_parse_suite, *)
        };
        virtual void TearDown() {
            delete testobj;
            //Called after every TEST_F(test_PersonParser_parse_suite, *)
        };
        wp::PersonParser* testobj;
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(test_PersonParser_parse_suite, case_name1)
{
    ASSERT_EQ(0, testobj->parse("zhangsan|22"));
	//TODO
}
 
