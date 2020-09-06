#include<stdio.h>
#include<stdlib.h>
#define basic 10;
int main(void)
{
     int a;
     float momeny = 0;
     printf("please enter the working hours per week");
     scanf("%d",&a);
        if(a <= 30)
        {
        momeny = a*10-300*0.15;
        printf("%f",momeny);
        }
        if(a <= 40 && a >30);
        momeny = a * 10 -300*0.15-(a-30)*0.2*10;
        printf("%f",momeny);
        if(a > 40)
        momeny = a*15 -300*0.15-(a-30)*0.2*10;
        printf("%f",momeny);
        
     

    system("pause");
    return 0;
}