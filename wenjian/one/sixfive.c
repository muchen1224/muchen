#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int a,c,d;
	char b;
	printf("请输入一个大写字母：");
	scanf("%c", &b);
	d = b - 'A' + 1;
	for (a = 0; a < d; a++)

	{
		for (c = 0; c < d; c++)
			printf(" ");
		for (c=0; c <= a ; c++)
			printf("%c", 'A'+c);
		for (c=a; c >= 0; c--)
			printf("%c", 'A'+c);
		printf("\n");
	}
    system("pause");
 return 0;
}
