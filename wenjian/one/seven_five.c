#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char ch; 
    printf("please enter texe to be analyzed:");
     while(( ch = getchar()) != '#')
  {
        switch(ch)
        {
            case'.':
           putchar('!');
           break; 

            case'!':
           putchar('!');
           putchar('!');
          break;

          default:
              putchar(ch);
              break;
          }
  }
  system("pause");
  return 0;     
       





   
}