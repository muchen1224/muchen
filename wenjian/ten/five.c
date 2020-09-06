#include<stdio.h>
#include<stdlib.h>
double max_min(double arr[],int m)
{
    double max = arr[0];
    double min = arr[0];
    for(int i = 0;i < m;i++)
       {
           if(max < arr[i])
             max = arr[i];
           if(min >arr[i])
              min = arr[i];
       }
       return (max - min);
}
int main(void)
{
    double arr[10] = {132.1,1212.2,454.5,153.2,123.9,213.4,3213.5,1215.3,31.3,12.2};
    double jie = max_min(arr,10);
    printf("The max element subscript arr is %f\n",jie);
    system("pause");
    return 0;
}