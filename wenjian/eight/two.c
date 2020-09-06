#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char ch;
    int m = 0;
    while((ch = getchar()) != EOF)
{
    m++;
    if(ch < ' ')
    {
        if('\t' == ch)
        {
            putchar('\\');
            putchar('t');
            printf(":%d",ch);
        }
        else if ('\n' == ch)
        {
            putchar('\\');
            putchar('n');
            printf(":%d",ch);
        }
        else
        {
            putchar('^');
            putchar(ch+64);
            printf(":%d",ch);
        }
    }
        else 
        {
            putchar(ch);
            printf(":%d",ch);
        }
    if(m%10  == 0)
    {
        printf("\n");
    }
}
    
  system("pause");
  return 0;  
}
