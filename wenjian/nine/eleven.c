#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
 int n = 0;
 int a = 1;
 int b = 1;
 int c = 0;
 int i = 0;
 scanf("%d", &n);
 printf("%5d %5d ", a, b);
 for (i = 0; i < n - 2;i++)
 {
   c = a + b;
   a = b;
   b = c;
   printf("%5d ", c);
 }
 printf("\n");
 system("pause");
 return 0;
}
