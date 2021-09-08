#include "../unity/unity.h"
#include "../unity/unity_internals.h"
#include"../inc/funtion.h"

#include<stdio.h>

/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

void test_name_is_valid(void)
{
    TEST_ASSERT_EQUAL_CHAR("Cierra","Cierra");
}

void test_name_is_valid1(void)
{
    TEST_ASSERT_EQUAL_CHAR("Alden ","Alden ");
}
void test_name_is_valid2(void)
{
    TEST_ASSERT_EQUAL_CHAR("Alden ","Alden ");
}
void test_name_is_valid3(void)
{
    TEST_ASSERT_EQUAL_CHAR("Alden ","Alden ");
}

int main()
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();
    /* Run Test functions */
    RUN_TEST(test_name_is_valid);
    RUN_TEST(test_name_is_valid1);
    RUN_TEST(test_name_is_valid2);
    RUN_TEST(test_name_is_valid3);
    /* Close the Unity Test Framework */
    return UNITY_END();
}