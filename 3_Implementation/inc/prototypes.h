/**
 * @file prototypes.h
 * @author ravali
 * @brief student record
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __PROTOTYPES_H__
#define __PROTOTYPES_H__



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/**
 * @brief Used macro
 * 
 */
#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "studentRecordSystem.bin"
/**
 * @brief Macro related to the students info
 * 
 */
#define MAX_FATHER_NAME 50
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_ADDRESS 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)
/**
 * @brief structure to store data
 * 
 */
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
/**
 * @brief Elements of structure
 * 
 */
typedef struct

{
    unsigned int student_id; // declare the integer data type
    char fatherName[MAX_FATHER_NAME];// declare the charecter data type
    char studentName[MAX_STUDENT_NAME];// declare the character data type
    char studentAddr[MAX_STUDENT_ADDRESS];// declare the character data type
    Date studentJoiningDate;// declare the integer data type
} s_StudentInfo;
/**
 * @brief prints the message in the middle of the head message
 * 
 * @param message 
 */
void printMessageCenter(const char* message);


/**
 * @brief  function verifies that a file has been created or not. 
 * If the file exists, the function return 1 otherwise returns 0.
 * 
 * @param path 
 * @return int 
 */
int isFileExists(const char *path);

/**
 * @brief function creates the file if not exist and copies the default password 
 *  in file header structure.
 * 
 */
void init();

/**
 * @brief It prints the message on the top of the console
 *  and prints the message as per operation.

 * @param message 
 */
void headMessage(const char *message);

/**
 * @brief 
This function displays the first welcomes screen of the “Student Record System Project in C” 
and asks the user to press any key to access the library application
 * 
 */
void welcomeMessage();
/**
 * @brief It validates the user name, author name ..etc. 
 * I have permitted this function to take the space in names.
 * 
 * @param name 
 * @return int 
 */
int isNameValid(const char *name);

/**
 * @brief 
This function read the date in the format of dd/mm/yyyy
 also it validates the entered date.
 * 
 * @param validDate 
 * @return int 
 */
int isValidDate(Date *validDate);

/**
 * @brief This function displays the library menu and asks the user to select the option. 
 * If the user selects 0, then the application will close
 * 
 */
void menu();
/**
 * @brief This function opens the binary file in append mode 
 * and writes the student and the details
 * 
 */
void addStudentInDataBase();

/**
 * @brief This function opens the binary file in reading mode 
 * and asks the user to enter the student id number which wants to 
 * search.  If the student info is not available on the list,
 *  it shows the message student not find in records.
 * 
 */
void searchStudent();

/**
 * @brief This function asks the student id from the user 
 * for the student to want to delete. In this function,
 *  I am creating a temporary binary file and copy all the data 
 * from the existing file except the book whose student id 
 * entered by the user. In the last renamed the temporary bin file with 
 * an existing binary file.
 * 
 */
void deleteStudent();

/**
 * @brief This function opens the file in rb+ mode (reading and writing). 
 * It asks the user for the new username and password. After taking the password and username 
 * it closes the application. Now user can 
 * use the application with a new password and username
 * 
 */
void updateCredential(void);

#endif