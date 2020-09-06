//100-101+102-103...+(-)n=
#include<stdio.h>
#include<stdlib.h>
int main()
{   
    int n;
    int s=0,m=100;
    
   printf("please you Enter a number 100-200 \n");
   
   scanf("%d",&n);
   while(n > 200 || n < 100)
        {
             printf("please you Enter a number 100-200 \n");
   
            scanf("%d",&n);
        }
     
       
       for(m=100;m <= n;m++)
       {
       s+= (m-99)%2 ==0 ? -m:+m;
      
       }
     printf("So the end result is %d\n",s);

    system("pause");
    return 0;
}