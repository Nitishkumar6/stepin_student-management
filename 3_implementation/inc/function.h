#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#ifndef __FUNTION_H__
#define __FUNTION_H__

//Used macro
#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "studentRecordSystem.bin"
// Macro related to the students info
#define MAX_FATHER_NAME_SIZE 50
#define MAX_STUDENT_NAME_SIZE 50
#define MAX_COURSE_NAME_SIZE 50
#define MAX_STUDENT_ADDRESS_SIZE 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)




typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;

typedef struct
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];
} sFileHeader;

typedef struct
{
    unsigned int student_id; 
    char fatherName[MAX_FATHER_NAME_SIZE];
    char studentName[MAX_STUDENT_NAME_SIZE];
    char studentAddr[MAX_STUDENT_ADDRESS_SIZE];
    Date studentJoiningDate;
    char courseName[MAX_COURSE_NAME_SIZE];
} s_StudentInfo;

void addStudent();

void searchStudentByCourse();

void searchStudentById();

void viewStudentDetails();

void removeStudent();

void updateCredentials(void);
#endif 