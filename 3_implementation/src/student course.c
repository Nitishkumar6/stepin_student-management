#include"../inc/funtion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void searchStudentByCourse()
{
    int found = 0;
    char course_name[MAX_COURSE_NAME_SIZE];
    char a[MAX_COURSE_NAME_SIZE];
    s_StudentInfo addStudentInfoInDataBase = {3};
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
    printf("\n\n\t\t\tEnter Student Course Name to search:");
    fflush(stdin);
    gets(course_name);
    
    while (fread (&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp))
    {
        
        if(is_string_equal(addStudentInfoInDataBase.courseName,course_name))
        {
            found = 1;
             
            printf("\n\t\t\tStudent id = %d",addStudentInfoInDataBase.student_id);
            printf("\n\t\t\tStudent name = %s",addStudentInfoInDataBase.studentName);
            printf("\t\t\tFather Name = %s",addStudentInfoInDataBase.fatherName);
            printf("\t\t\tCourse Name = %s",addStudentInfoInDataBase.courseName);
            printf("\t\t\tStudent Address = %s",addStudentInfoInDataBase.studentAddr);
            printf("\t\t\tStudent Admission Date(day/month/year) =  (%d/%d/%d)",addStudentInfoInDataBase.studentJoiningDate.dd,
                addStudentInfoInDataBase.studentJoiningDate.mm, addStudentInfoInDataBase.studentJoiningDate.yyyy);    
            printf("\n");
        }
    }
    if(found)
    {
       
    }
    else
    {
        printf("\n\t\t\tNo Records");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}