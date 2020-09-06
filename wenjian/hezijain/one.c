#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x=0,y=0;
    int i=0;
    printf("please enter two number x,y\n");
    scanf("%d%d",&x,&y);
    i=x;
    x=y;
    y=i;
    printf("so after swapping the values x=%3d,y=%3d",x,y);
   system("pause");
    return 0;
}