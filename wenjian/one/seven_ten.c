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
     printf("1)����\n2)����\n3)�ѻ飬����\n4)�ѻ飬����\n");
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
     
     printf("��������ʵ�ʵĹ��ʣ�");
     scanf("%d",&b);
     if(b <= number);
     {
     c = b * num;
     }
     if(b > number)
     {
     c = number * num + (b-number) * num_;
     }
     printf("����ܵõ��Ĺ���Ϊ��%f\n",c);
     }
     
     
     system("pause");
     return 0;
}