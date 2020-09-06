#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void input_(char *input,int num )
{
    printf(" %d character\n",num);
    for(int i = 0;i < num ;i++)
    {
        char ch = 0;
       ch = getchar();
        fflush(stdin);
        if(isblank(ch))
        {
            return;
        }
        else
        {
            input[i] = ch;
        }
       
    }
     return;

}
int main(void)
{
    char input[265];
    int number;
    printf("please Enter a number");
    scanf("%d",&number);
   
    input_(input,number);
    printf("you input ");
    for(int j = 0;j < number;j++)
       {
           printf("%c",input[j]);
       }
    system("pause");
    return 0;
}