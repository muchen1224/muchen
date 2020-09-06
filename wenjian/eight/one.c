#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char ch;
    int number=0;
    while((ch = getchar()) != '\n')
{
      number++;
}
      printf("there are %d characters in the file\n",number);
  system("pause");  
  return 0;
}
