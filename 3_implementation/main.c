#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include"inc/funtion.h"
#include"src/search_student_course.c"
#include"src/search_student.c"
#include"src/Add_Student.c"
#include"src/view_student_details.c"
#include"src/remove_student.c"
#include"src/update.c"


void printMessage(const char* message);
void currentState(const char *message);
void welcomeMessage();
int checkIsNameValid(const char *name);
int  checkIsLeapYear(int year);
int checkIsDateValid(Date *validDate);
void addStudent();
void searchStudentById();
void searchStudentByCourse();
int is_string_equal(char* str1, char* str2);
void viewStudentDetails();
void removeStudent();
void updateCredentials(void);
void displayMenu();
void login();
int checkIsFileExists(const char *path);
void init();



int main()
{
    init();
    welcomeMessage();
    login();
    return 0;
}

void printMessage(const char* message)
{
    int len =0;
    int pos = 0;
    
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        
        printf(" ");
    }
    
    printf("%s",message);
}

void currentState(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############   Student Record Management System Project in C   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessage(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
//Display message
void welcomeMessage()
{
    currentState("LTTS FOLKS");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    To                     =");
    printf("\n\t\t\t        =               Student Record              =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t Enter any key to continue.....");
    getch();
}

//to check whether the name is valid or not
int checkIsNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}

//to check whether the year is leap year year or not
int  checkIsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

// to check whether the date is valid or not
int checkIsDateValid(Date *validDate)
{
    
    if (validDate->yyyy > MAX_YR ||
            validDate->yyyy < MIN_YR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    
    if (validDate->mm == 2)
    {
        if (checkIsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
   
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}




// check whether two strings same or not
int is_string_equal(char* str1, char* str2)
{
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') 
  {
    if (str1[i] != str2[i])
        return 0; 
    i++;
  }
  
  if (str1[i] == '\0' && str2[i] == '\0') 
    return 0;
  return 1;
}

// to view te details of students 


// to remove student data



//to display main menu
void displayMenu()
{
    int choice = 0;
    do
    {
        currentState("MAIN - MENU");
        printf("\n\n\n\t\t\t1.Add Student");
        printf("\n\t\t\t2.Search Student By Id");
        printf("\n\t\t\t3.Search Student By course");
        printf("\n\t\t\t4.View Student");
        printf("\n\t\t\t5.Delete Student");
        printf("\n\t\t\t6.Update Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            searchStudentById();
            break;
        case 3:
            searchStudentByCourse();
            break;
        case 4:
            viewStudentDetails();
            break;     
        case 5:
            removeStudent();
            break;
        case 6:
            updateCredentials();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you !!!\n\n\n\n\n");
            exit(1);
            break;   
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again.....");
        }                                            
    }
    while(choice!=0);                                        
}

//login function
void login()
{
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    int count=0;
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    currentState("Login");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    do
    {
        printf("\n\n\n\t\t\t\tUsername:");
        fgets(userName,MAX_SIZE_USER_NAME,stdin);
        printf("\n\t\t\t\tPassword:");
        fgets(password,MAX_SIZE_PASSWORD,stdin);
        if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
        {
            displayMenu();
        }
        else
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
            count++;
        }
    }
    while(count<=3);
    if(count>3)
    {
        currentState("Login Failed");
        printf("\t\t\t\t\tSorry,Unknown User.");
        getch();
        system("cls");
    }
}


int checkIsFileExists(const char *path)
{
   
    FILE *fp = fopen(path, "rb");
    int status = 0;
    
    if (fp != NULL)
    {
        status = 1;
        
        fclose(fp);
    }
    return status;
}
void init()
{
    FILE *fp = NULL;
    int status = 0;
    const char setUsername[] ="ltts folks\n";
    const char setPassword[] ="ltts folks\n";
    sFileHeader fileHeaderInfo = {0};
    status = checkIsFileExists(FILE_NAME);
    if(!status)
    {
        
        fp = fopen(FILE_NAME,"wb");
        if(fp != NULL)
        {
            
            strncpy(fileHeaderInfo.password,setPassword,sizeof(setPassword));
            strncpy(fileHeaderInfo.username,setUsername,sizeof(setUsername));
            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }
}