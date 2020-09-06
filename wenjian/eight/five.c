#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char ch;
    int upper = 100;
    int lower = 0;
    int guest = 50;
 printf("I guest the number is 50.Is rigrt(Y/N)?");
 scanf("%c",&ch);
getchar();
 
 while('Y' == ch)
 {
     printf("Ok,the number you chosen is bigger or smaller than I guest？（B/S)");
     scanf("%c",&ch);
     getchar();
     if('B' == ch)
     {
         lower = guest;
         guest = (lower + guest) / 2;
     }
     else
     {
         upper = guest;
         guest = (upper + lower) / 2;
     }
      printf("I guest the number is %d, Is it right(Y/N)?", guest);
        scanf("%c", &ch);
        getchar();
 }
  printf("HAHA, I win!");
  system("pause");
  return 0;

}