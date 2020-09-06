#include<stdio.h>
#include<stdlib.h>
double pow_recursive(double base, double index)
{
    if (index > 0)
    {
        index--;
        return (base * pow_recursive(base, index));
    }
    if (0 == index)
    {
        if (base == 0)
        {
            printf("The base number is 0 is not defined!\n");
        }
        return 1;
    }
    if (index < 0)
    {
        index++;
        double tmp = 1 / base;
        return (tmp * pow_recursive(base, index));
    }
}
int main(void)
{
    double base = 0.0;
    double index = 0.0;
    double result = 0.0;

    printf("Enter the base number:");
    scanf("%lf", &base);
    fflush(stdin);

    printf("Enter the index number:");
    scanf("%lf", &index);
    fflush(stdin);

    result = pow_recursive(base, index);
    printf("base number: %lf, index number: %lf, the result: %lf\n", base, index, result);
    system("pause");
    return 0; 
}