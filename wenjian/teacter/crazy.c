#include<stdio.h>
#include<stdlib.h>
int main(void)
{ int i=4;
 int k=0;
k=(i++)+(++i)+(++i);
printf("%d,%d",i,k);
  /*int i=16,j=5;
  j+=(++i)+1;

 printf("%d,%d",i,j);
 /*int x=30,y=50,z=80;
 if(x>y||x<z&&y>z)
 z=x;x=y
 while(n++<=1) 
 printf("%d\t",n); 
 printf("%d\n",n);
 
/*nt x=3;
do

  {
  printf("%3d",x-=2);
}while(--x);
/*
while(x<15)
{
  y++,x+=++y;
  printf("%d,%d\n",x,y);
}*/
 system("pause");

 return 0;
}