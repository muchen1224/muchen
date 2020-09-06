#include <stdio.h>
#include<stdlib.h>
int main(void)
{
    char ch;
    int number = 0;
    printf("please enter texe to be anlyzed:");
    while((ch = getchar()) != '#')
    {
         if(ch == 'e')
           {
               ch = getchar();
               if(ch == 'i')
                  number++;
           }
           else
               ch = getchar();
        
    }
     printf("So,ei number:%d",number);
         system("pause");
         return 0;

}