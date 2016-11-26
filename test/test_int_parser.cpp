
#include <int_parser.h>
#include <gtest/gtest.h>
	
	
int main(int argc, char **argv)
{
 	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
/**
 * @brief 
**/
class test_IntParser_IntParser_suite : public ::testing::Test{
    protected:
        test_IntParser_IntParser_suite(){};
        virtual ~test_IntParser_IntParser_suite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_IntParser_IntParser_suite, *)
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_IntParser_IntParser_suite, *)
        };
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(test_IntParser_IntParser_suite, case_name1)
{
	//TODO
}
 
/**
 * @brief 
**/
class test_IntParser_parse_suite : public ::testing::Test{
    protected:
        test_IntParser_parse_suite(){};
        virtual ~test_IntParser_parse_suite(){};
        virtual void SetUp() {
            testobj = new wp::IntParser();
            //Called befor every TEST_F(test_IntParser_parse_suite, *)
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_IntParser_parse_suite, *)
            delete testobj;

        };
    wp::IntParser* testobj;
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(test_IntParser_parse_suite, case_name1)
{
	ASSERT_EQ(0, testobj->parse("123"));
}
 
/**
 * @brief 
**/
class test_IntParser_to_string_suite : public ::testing::Test{
    protected:
        test_IntParser_to_string_suite(){};
        virtual ~test_IntParser_to_string_suite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_IntParser_to_string_suite, *)
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_IntParser_to_string_suite, *)
        };

};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(test_IntParser_to_string_suite, case_name1)
{

}
 
