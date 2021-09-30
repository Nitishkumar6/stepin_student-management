
#include "ll.h"

 int count =0;
 int option = 0;
 int i = 0;
 int n = 0;
 int j = 0;
 float present = 75.00;
 char money = 'P';
 float tdays = 1;
 int eligible = 0;

void add()
{
    
 printf("Enter the total ");
    printf("number of working days \n");
    scanf("%f", &tdays);
  
    printf("Enter the number");
    printf("of students \n");
    scanf("%d", &n);
  
    for (i = 0; i < n; i++) {
 
        Student s;
        printf("Student number %d \n",
               (i + 1));
  
        printf("Enter the name of"
               " the student \n");
        scanf("%s", s.name);
  
        printf("Enter the roll number \n");
        scanf(" %d", &s.rno);
  
        printf("Enter the fees of the"
               "student 'P' for paid "
               ", 'N' for not paid \n");
        scanf(" %c", &s.fees);
  
        printf("Enter the number of"
               "days the student was "
               "present \n");
        scanf("%f", &s.days);
  
        s.attend = (s.days/tdays)*100;
        printf("student attendence = %f \n",
               s.attend);

        insert_at_end(s);

    } 


}

void execute()
{
    //printf("Present : %f\n",present);
    printf(
        " Enter the serial number"
        "to select the option \n");
    printf(" 1. To show Eligible"
           "candidates \n");
    printf(" 2. To delete the "
           "student record \n");
    printf(" 3. To change the "
           "eligibility criteria \n");
    printf(" 4. Reset the "
           "eligibility criteria \n");
    printf(" 5. Print the list "
           "of all the student \n");
    printf(" Enter 0 to exit \n");
  
    scanf("%d", &option);
  
    // Switch Statement for choosing
    // the desired option for the user
    float ps;
    switch (option) {
    case 1:
        eligibleStudents();
        execute();
        break;
  
    case 2:
        deleteRecord();
        execute();
        break;
  
    case 3:
        printf("Old Attendance "
               "required = %f | ",
              present);

        printf(
            "Enter the updated "
            "attendence required : ");
        scanf("%f", &ps);
        present = ps;

        printf("Eligibility Criteria updated %f\n",present);
        execute();
        break;
  
    case 4:
        present = 75.00;
        money = 'P';
        printf("Eligibility creitria reset \n");
        execute();
        break;
  
    case 5:
        printStudents();
        execute();
        break;
  
    case 6:
        execute();
        break;
  
    case 0:
        exit(0);
        break;
  
    default:
        printf("Enter number only from 0-4 \n");
        execute();
    }
}

void eligibleStudents()
{
    printf("________________"
           "________________"
           "_______________"
           "_____________ \n");
    printf("Qualified student are = \n");
    eligible = 0;
    traverse();
    printf("________________"
           "________________"
           "_______________"
           "_____________ \n");
}

void deleteRecord()
{
    int a = 0;
    printf("________________"
           "________________"
           "_______________"
           "_____________ \n");
    printf("Enter the roll number of "
           "the student to delete it ");
    scanf("%d", &a);
    delete(a);
    printf("________________"
           "________________"
           "_______________"
           "_____________ \n");
      
}

void printStudents()
{
   printf("________________"
           "________________"
           "_______________"
           "_____________ \n");
 
  print();
  printf("________________"
           "________________"
           "_______________"
           "_____________ \n");


}

