#include<stdio.h>
#include<stdlib.h>
void main()
{
	char a[5] = { '*','*','*','*','*' };
	int i, j, k;
	char space = ' ';
	for (i = 0; i < 5; i++)
	{
		printf("\n");
		for (j = 4; j >i; j--)
			printf("%c", space);
		for (k = 0; k < 5; k++)
			printf("%c", a[k]);
	}
	printf("\n");
    system("pause");
}
