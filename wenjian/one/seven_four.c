#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  char ch = 0;
  printf("please enter texe to be analyzed:");
  while(( ch = getchar()) != '#')
  {
        if('.' == ch)
        {
           putchar('!');
        }
        else if('!' == ch)
          {
           putchar('!');
           putchar('!');
          }
          else
          {
              putchar(ch);
          }
  }
  system("pause");
  return 0;     
       
}