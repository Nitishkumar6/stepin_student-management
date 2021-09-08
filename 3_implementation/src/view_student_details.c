#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include"../inc/funtion.h"
void viewStudentDetails()
{
    int found = 0;
    s_StudentInfo addStudentInfoInDataBase = {0};
    FILE *fp = NULL;
    unsigned int countStudent = 1;
    currentState("VIEW STUDENT DETAILS");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    while (fread (&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp))
    {
        printf("\n\t\t\tStudent Count = %d\n\n",countStudent);
        printf("\t\t\tStudent id = %u\n",addStudentInfoInDataBase.student_id);
        printf("\t\t\tStudent Name = %s",addStudentInfoInDataBase.studentName);
        printf("\t\t\tFather Name = %s",addStudentInfoInDataBase.fatherName);
        printf("\t\t\tCourse Name = %s",addStudentInfoInDataBase.courseName);
        printf("\t\t\tStudent Address = %s",addStudentInfoInDataBase.studentAddr);
        printf("\t\t\tStudent Admission Date(day/month/year) =  (%d/%d/%d)\n\n",addStudentInfoInDataBase.studentJoiningDate.dd,
               addStudentInfoInDataBase.studentJoiningDate.mm, addStudentInfoInDataBase.studentJoiningDate.yyyy);
        found = 1;
        ++countStudent;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}