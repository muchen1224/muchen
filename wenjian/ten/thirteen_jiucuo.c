
#include <stdio.h>
#include <stdlib.h>
 
double aver(double a[5])
{
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += a[i];
    }
    return sum / 5;
}
 
double allaver(double a[3][5])
{
    double sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += aver(a[i]);
    }
    return sum / 3;
}
 
double maxx(double* a, double* b)
{
    double max = 0;
    for(;a < b; a++)
    {
        max = max > *a ? max : *a;
    }
    return max;
}
 
int main(void)
{
    double a[3][5];
    for (int i = 0; i < 3; ++i)
    {
        printf("input a sequence of 5 number:");
        for (int j = 0; j < 5; ++j) {
            scanf("%lf", &a[i][j]);
        }
    }
    double sum = 0;
    for (int k = 0; k < 3; ++k) {
        printf("%.2lf ", aver(a[k]));
    }
    printf("\n");
    printf("%.2lf\n", allaver(a));
    printf("%.2lf\n", maxx(*a, *a + 15));
    system("pause");
    return 0;
}

