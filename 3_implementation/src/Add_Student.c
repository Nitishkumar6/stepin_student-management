#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include"../inc/funtion.h"
void addStudent()
{
    s_StudentInfo addStudentInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    currentState("ADD NEW Students");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tStudent ID  = ");
    fflush(stdin);
    scanf("%u",&addStudentInfoInDataBase.student_id);
    do
    {
        printf("\n\t\t\tFather Name  = ");
        fflush(stdin);
        fgets(addStudentInfoInDataBase.fatherName,MAX_FATHER_NAME_SIZE,stdin);
        status = checkIsNameValid(addStudentInfoInDataBase.fatherName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tStudent Name  = ");
        fflush(stdin);
        fgets(addStudentInfoInDataBase.studentName,MAX_STUDENT_NAME_SIZE,stdin);
        status = checkIsNameValid(addStudentInfoInDataBase.studentName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    printf("\n\t\t\tCourse Name  = ");
    fflush(stdin);
    fgets(addStudentInfoInDataBase.courseName,MAX_COURSE_NAME_SIZE,stdin);;
    do
    {

        printf("\n\t\t\tStudent Address  = ");
        fflush(stdin);
        fgets(addStudentInfoInDataBase.studentAddr,MAX_STUDENT_ADDRESS_SIZE,stdin);
        status = checkIsNameValid(addStudentInfoInDataBase.studentAddr);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        
        printf("\n\t\t\tEnter date in format (day/month/year): ");
        scanf("%d/%d/%d",&addStudentInfoInDataBase.studentJoiningDate.dd,&addStudentInfoInDataBase.studentJoiningDate.mm,&addStudentInfoInDataBase.studentJoiningDate.yyyy);
        status = checkIsDateValid(&addStudentInfoInDataBase.studentJoiningDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    fwrite(&addStudentInfoInDataBase,sizeof(addStudentInfoInDataBase), 1, fp);
    fclose(fp);
}