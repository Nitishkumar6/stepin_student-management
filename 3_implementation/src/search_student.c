#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include"../inc/funtion.h"

void searchStudentById()
{
    int found = 0;
    int studentId =0;
    s_StudentInfo addStudentInfoInDataBase = {1};
    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    currentState("SEARCH STUDENTS");
    
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter Student ID NO to search:");
    fflush(stdin);
    scanf("%u",&studentId);
    while (fread (&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp))
    {
        if(addStudentInfoInDataBase.student_id == studentId)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tStudent id = %d\n",addStudentInfoInDataBase.student_id);
        printf("\t\t\tStudent name = %s",addStudentInfoInDataBase.studentName);
        printf("\t\t\tFather Name = %s",addStudentInfoInDataBase.fatherName);
        printf("\t\t\tCourse Name = %s",addStudentInfoInDataBase.courseName);
        printf("\t\t\tStudent Address = %s",addStudentInfoInDataBase.studentAddr);
        printf("\t\t\tStudent Admission Date(day/month/year) =  (%d/%d/%d)",addStudentInfoInDataBase.studentJoiningDate.dd,
               addStudentInfoInDataBase.studentJoiningDate.mm, addStudentInfoInDataBase.studentJoiningDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}