//正奇数的和 例输入103 求1+3+5+...+103的和
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n = 1,m =0,s = 1;
    while(1)
    {
        printf("please you Enter a number to 200-300 \n");
        scanf("%d",&m) ==1;
        getchar();
        if(m % 2 == 1 && m >= 200 && m <= 300)
        {
            for(n =1;n<m;n++)
            {
                n+=2;
                s+=n;
            }
            printf("So the end result is %d\n",s);
            break;
        }
        else
        continue;

    }
    
    system("pause");
    return 0;
}