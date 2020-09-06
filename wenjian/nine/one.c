#include <stdio.h>
#include<stdlib.h>
double min(double, double);
int main(void)
{
double x, y;
printf("Enter two numbers (q to quit): ");
while (scanf("%lf %lf", &x, &y) == 2)
{
printf("The smaller number is %f.\n", min(x,y));
printf("Next two values (q to quit): ");
}
printf("Bye!\n");
system("pause");
return 0;
}
double min(double a, double b)
{
return a < b ? a : b;
}