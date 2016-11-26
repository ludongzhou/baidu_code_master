
#include <factory.h>
#include <gtest/gtest.h>
	
	
int main(int argc, char **argv)
{
 	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
/**
 * @brief 
**/
class test_createT_suite : public ::testing::Test{
    protected:
        test_createT_suite(){};
        virtual ~test_createT_suite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_createT_suite, *)
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_createT_suite, *)
        };
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(test_createT_suite, case_name1)
{
	//TODO
}
 
/**
 * @brief 
**/
class test_BaseFactory_create_instance_suite : public ::testing::Test{
    protected:
        test_BaseFactory_create_instance_suite(){};
        virtual ~test_BaseFactory_create_instance_suite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_BaseFactory_create_instance_suite, *)
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_BaseFactory_create_instance_suite, *)
        };
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(test_BaseFactory_create_instance_suite, case_name1)
{
	//TODO
}
 
/**
 * @brief 
**/
class test_DerivedRegister_DerivedRegister_suite : public ::testing::Test{
    protected:
        test_DerivedRegister_DerivedRegister_suite(){};
        virtual ~test_DerivedRegister_DerivedRegister_suite(){};
        virtual void SetUp() {
            //Called befor every TEST_F(test_DerivedRegister_DerivedRegister_suite, *)
        };
        virtual void TearDown() {
            //Called after every TEST_F(test_DerivedRegister_DerivedRegister_suite, *)
        };
};
 
/**
 * @brief 
 * @begin_version 
**/
TEST_F(test_DerivedRegister_DerivedRegister_suite, case_name1)
{
	//TODO
}
 
