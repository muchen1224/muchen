#include<stdio.h>
#include<stdlib.h>
void input_(char *input,int num)
{
     printf("please Enter %d characters",num);
     for(int i = 0;i < num ;i++)
     {
        input[i] = getchar();
     }
     return;
}
int main(void)
{
   char input[256];
    int number = 0;
    printf("Enter the number of character:");
    scanf("%d", &number);
    fflush(stdin);

    input_(input, number);
    printf("You input:");
    for (int im = 0; im < number; im++)
    {
        printf("%c", input[im]);
    }
    printf("\n");
    system("pause");
    return 0;

}