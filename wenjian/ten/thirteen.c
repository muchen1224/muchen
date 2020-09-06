#include<stdio.h>
#include<stdlib.h>
double arr(double number_[][5],int m)
{
    for(int i = 0;i < m;i++)
    {
     for(int r = 0;r < 5;r++)
     {
     scanf("%lf",&number_[i][r]);
     
    }
    }
    return;
}
double cal_avg_1d(double number_[][5], int cols)
{
    double sum = 0.0;
    for (int i = 0; i < cols; i++)
    {
        for(int r = 0;r < 5;r++)

        sum += number_[i][r];
        printf("The meizupingjunshu %f",sum);
        break;
    }

    
}
double cal_avg_2d(double number_[][5], int rows)
{
    double sum = 0.0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum += number_[i][j];
        }
    }
    return (sum / (5 * rows));
}
double arr_max_element(double number_[][5], int rows)
{
    double max = 0.0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (max < number_[i][j])
            {
                max = number_[i][j];
            }
        }
    }
    return max;
}
void print_double_2d(double number_[][5], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%lf ", number_[i][j]);
        }
        printf("\n");
    }
    return;
}
int main(void)
{
    double number_[3][5];
    printf("Enter 15 double number:");
    arr(number_, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("average of row %d is %lf\n", i, cal_avg_1d(number_[i], 5));
    }
    printf("average of 15 double numbers is %lf\n", cal_avg_2d(number_, 3));
    printf("The max element of array is %lf\n", arr_max_element(number_, 3));

    return 0;
}
