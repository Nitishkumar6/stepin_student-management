#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include"../inc/funtion.h"
//attendence Details
void searchByAttendence()
{
    int found = 0;
    int percentage;
    int status;
    int countStudent = 1;
    s_StudentInfo addStudentInfoInDataBase = {1};
    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    currentState("SEARCH STUDENTS by Attendence percentage");
    
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    
    do
    {
        printf("\n\t\t\tEnter percentage of attendence :");/* code */
        fflush(stdin);
        scanf("%u",&percentage);
        if(percentage<0 || percentage<=100)
        {
            status = 1;
        }
        if(!status)
        {
            printf("\n\t\t\tPlease enter the valid number of presents.\n");
        }
    } while (!status);

    while (fread (&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp))
    {   if((((addStudentInfoInDataBase.attendence)/180)*100) <= percentage)
        {
            printf("\n\t\t\tStudent Count = %d\n\n",countStudent);
            printf("\t\t\tStudent id = %u\n",addStudentInfoInDataBase.student_id);
            printf("\t\t\tStudent Name = %s",addStudentInfoInDataBase.studentName);
            printf("\t\t\tFather Name = %s",addStudentInfoInDataBase.fatherName);
            printf("\t\t\tCourse Name = %s",addStudentInfoInDataBase.courseName);
            printf("\t\t\tStudent Address = %s",addStudentInfoInDataBase.studentAddr);
            printf("\t\t\tStudent Admission Date(day/month/year) =  (%d/%d/%d)\n",addStudentInfoInDataBase.studentJoiningDate.dd,
                addStudentInfoInDataBase.studentJoiningDate.mm, addStudentInfoInDataBase.studentJoiningDate.yyyy);
            printf("\t\t\tNumber of present(out of 180) = %d\n\n",addStudentInfoInDataBase.attendence);
            found = 1;
            ++countStudent;
        }
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
