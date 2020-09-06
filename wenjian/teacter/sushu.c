#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    int a;
    int i,j;
    printf("please input the upper number:");
    scanf("%d",&a);
    for(i = 2;i <= a;i++)
    {
     for(j=2;j <= sqrt((double)i);j++)
        if(i % j == 0)
          break;
          if(j > sqrt(i))
            printf("%5d",i);
    }
    system("pause");
    return 0;
}