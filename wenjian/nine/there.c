#include<stdio.h>
#include<stdlib.h>
void chline(char ch1,int a,int b)
{
    int e,f;  
    char ch2;
    ch1 =ch2;
    for(f=0;f < b;f++)
    {
        for(e=0;e <a;e++)
        {
           putchar(ch1);
        }
        printf("\n");
    }      
}
int main(void)
{
    char ch;
    int m,n;
    scanf("%c %d %d",&ch,&m,&n);
    getchar();
   
   
      chline(ch,m,n);
  printf("goodbye!\n");
   system("pause");
   return 0;

}
