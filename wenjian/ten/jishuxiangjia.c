#include<stdio.h>
#include<stdlib.h>
int main(void)
{
   int number = 0;
   int a = 1;
   int n;
   puts("请输入一个正整数");
   scanf("%d",&n);
   if(n%2 == 0)
     {
         while(a < n)
         {
             number +=a;
             a +=2;
         }
       

     }
     else
     {
         while(a <= n)
         {
             number +=a;
             a +=2;
         }
      
     }

     printf("所以该正整数奇数的和为：%d\n",number);
     system("pause");
     return 0;
}