#include<stdio.h>
#include<stdlib.h>
#define num 0.15;
#define num_ 0.28;
int main(void)
{   
     int number = 0;
     int a = 0;
     int b = 0;
     float c = 0;
     while(1)
     {
     printf("please you one of fhe following options:\n");
     printf("1)单身\n2)户主\n3)已婚，共有\n4)已婚，离异\n");
     scanf_s("%d",&a);
    
     
          switch(a)
          {
          case 1: 
            number = 17850;
            break;
          case 2:
            number = 23900;
            break;
          case 3:
            number = 29750;
            break;
          case 4:
            number = 14875;
            break;
          default:
          printf("buxing\n");
          break;         
      
            
          }
     
     printf("请输入你实际的工资：");
     scanf("%d",&b);
     if(b <= number);
     {
     c = b * num;
     }
     if(b > number)
     {
     c = number * num + (b-number) * num_;
     }
     printf("最后能得到的工资为：%f\n",c);
     }
     
     
     system("pause");
     return 0;
}