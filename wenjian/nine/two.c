#include<stdio.h>
#include<stdlib.h>
char chline(char *, int, int);
int main()
{
    char ch;
    int i,j;
    printf("请输入一个字母和两个整数：");
    scanf("%c%d%d",&ch,&i,&j);
    chline(ch,i,j);
    system("pause");
    return 0;


}
char chline(char a, int b, int c)
{
    int m=0;
    int n=0;
    char ch;
    for(;m < b;m++)
    {
       for(;n <c;n++)
       {
       printf("%c",a);
       }
       printf("\n");
    }
}