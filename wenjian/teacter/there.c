//两百以内能被3整除且个位为6
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
   
    for(int i= 0;i<=200;i++)
    {
        if(i%3==0&&i/10==0.6)
            printf("%d\n",i);
        else if(i%3==0&&i%10==6)
            printf("%d\n",i);
    }
    system("pause");
    return 0;
}