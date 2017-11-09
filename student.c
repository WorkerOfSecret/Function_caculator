#include<stdio.h>

// ANSI COLOUR
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

struct person 
{
    int id;
    char name[30];
    char phone[20];
};

void main()
{
    struct person student[5];
    int i;
    FILE fr;
    printf (GREEN"\t\tInput student information: Name ID Phone\n"RESET);
    
   /* if (fr = fopen("student_data.txt","r") == NULL);
        fr = fopen("student_data.txt","w");
   */ 
    for (i=0; i < 5; i++)
    {
        printf(">>> ");
        scanf("%s %d %s", student[i].name, &student[i].id, student[i].phone);
        getchar();
    }
    
    printf("Student information: \n");
    for (i = 0; i < 5; i++)
    {
        printf(CYAN"\n\tStudent.no%d\n"RESET,i+1);
        printf(YELLOW"_ID: %d\n_Name: %s\n_Phone: %s\n"RESET,student[i].id,student[i].name,student[i].phone);
        printf("\n\n");
    }
}
