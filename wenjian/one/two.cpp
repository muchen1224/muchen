//创建两个double类型数组，提示用户为第一个数据输入8个值，第二个数组是第一个数组之和
#include<stdio.h>
#include<stdlib.h>
#define SIZE 8
int main(void)

{
	int a;
	double  arr[SIZE];
	double  arr_cumul[SIZE];
	printf("你 you shuru eight shuzi：");
	for (a = 0; a < SIZE; a++)
	{
	    printf("value #%d: ", a + 1);
	    scanf("%f", &arr[a]);
     }
	arr_cumul[0] = arr[0];
	for (a = 1; a < SIZE; a++)
		arr_cumul[a] = arr[a] + arr_cumul[a - 1];
	for (a = 0; a < SIZE; a++)
	     printf("%f", arr[a]);
	printf("\n");
	for (a = 0; a < SIZE; a++)
	     printf("%f", arr_cumul[a]);
	printf("\n");
	system("pause"); 
	return 0;
}
