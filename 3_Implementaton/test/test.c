#include "ll.h"
#include "unity.h"
//#include "ll.c"
extern int count;
extern int option;
extern int i;
extern int n;
extern int j;
extern float present;
extern char money;
extern float tdays;
extern int eligible;

/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

void add_student_record(void){
    tdays = 100;
    n = 1;
    Student s;
    strcpy(s.name,"TEST");
    s.rno = 1;
    s.fees = 'P';
    s.days = 90;
    s.attend = (s.days/tdays)*100;
    insert_at_end(s);

    TEST_ASSERT_EQUAL_INT(1,count);
}

void check_eligibility(void){
     eligibleStudents();
     TEST_ASSERT_EQUAL_INT(1,eligible);
}

void reject_eligibility(void){
     eligibleStudents();
     TEST_ASSERT_EQUAL_INT(0,eligible);
}


void change_eligibility(void){
     present = 99.00;
     TEST_ASSERT_EQUAL_FLOAT(present,present);
}

void reset_eligibility(void){
     present = 75.00;
     TEST_ASSERT_EQUAL_FLOAT(present,present);
}


void delete_student_record(void){
    delete(1); // roll number
    TEST_ASSERT_EQUAL_INT(0,count);
}


int main(void)
{
	/* Initiate the Unity Test Framework */
	UNITY_BEGIN();

	/* Run Test functions */
	RUN_TEST(add_student_record);
        RUN_TEST(check_eligibility);
        RUN_TEST(change_eligibility);
        RUN_TEST(reject_eligibility);
        RUN_TEST(reset_eligibility);
        RUN_TEST(delete_student_record);

	/* Close the Unity Test Framework */
	return UNITY_END();
}
