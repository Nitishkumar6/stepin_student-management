#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int rno;
    char fees;
    float days;
    float attend;
}Student;

struct Node {
    Student student;
    struct Node *next;
};

void add();
/**
 * @brief To add student details 
 * 
 */
void eligibleStudents();
/**
 * @brief To update the eligiblity of each students
 * 
 */

void execute();
/**
 * @brief To execute all other functions
 * 
 */
void printStudents();
/**
 * @brief To print student details
 * 
 */
void deleteRecord();
/**
 * @brief To delete student record
 * 
 */

#endif