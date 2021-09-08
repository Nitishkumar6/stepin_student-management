#include "student.h"
/**
 * @brief this code runs first where user is given two 
 * options to enter student data or to exit the program
 * 
 */
extern int option;

int main()
{
    printf("Welcome to Student "
           "database registration \n");
  
    printf("Enter 0 to exit \n");
    printf("Enter 1 to add student record \n");
  
    scanf("%d", &option);
  
    // Switch Statements
    switch (option) {
    case 0:
        exit(0);
  
    case 1:
        add();
        execute();
        break;
    default:
        printf("Only enter 0 or 1");
        execute();
    }
    return 0;
}