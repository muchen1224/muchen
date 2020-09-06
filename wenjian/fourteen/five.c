#include<stdio.h>
#include<stdlib.h>
//存储名和姓
struct name
{
   char xing[30];
   char ming[30];
};
//三个成员 name结构  grade数组
struct student          
{       
    struct name names;
    double grade[3];
    double average;
    
};
#define CSIZE 4
int main(void)
{
    struct student students[CSIZE];
    //d
    for(int i = 0;i <CSIZE;i++)
    {
        printf("please you enter xing:");
        fgets(students[i].names.xing,30,stdin);
        printf("please enter ming:");
        fgets(students[i].names.ming,30,stdin);
        printf("Enter three grades of this student: ");
       
        for(int j = 0;j < CSIZE ; j++)
        {
            scanf("%1f",&students[i].grade[j]);
            getchar() != '\n';
        }
        
     }
        //e
         for (int i = 0; i < CSIZE; i++)
    {
        double total_grade = 0.0;
        for (int j = 0; j < 3; j++)
        {
            total_grade += students[i].grade[j];
        }
        students[i].average = total_grade / 3;
    }
    //f
     for (int i = 0; i < CSIZE; i++)
    {
        printf("Student: %s, %s, grade: %.2lf, %.2lf, %.2lf, average: %.2lf\n", students[i].names.xing, students[i].names.ming,
            students[i].grade[0], students[i].grade[1], students[i].grade[2], students[i].average);
    }
    // g
    double total_grades = 0.0;
    for (int i = 0; i < CSIZE; i++)
    {
        total_grades += students[i].average;
    }
    printf("All students' average grade is %.2lf\n", total_grades / CSIZE);
    system("pause");
    return 0;
   
    
}



