 #include <stdio.h>
#include<stdlib.h>
int main(void)
{
    int ch;
    int even_number = 0;
    int even_average =0;
    int odd_number = 0;
    int odd_average = 0;
    while(scanf("%d",&ch))
      if(ch == 0)
          break;
      else if(ch % 2 == 0)
      {
          even_number++;
        even_average += ch;
      }
      else
      {
          odd_number++;
          odd_average += ch;
          
      }
      printf("偶数的个数：%4d,平均数：%4d\n",even_number,even_average/even_number);
      printf("奇数的个数：%4d，平均数：%4d\n",odd_number,odd_average/odd_number);
      system("pause");
      return 0;
      
}