#include<stdio.h>
#include<stdlib.h>
void print_n_char(char ch, int repeat_time, int repeat_row)
{
    for (int i = 0; i < repeat_row; i++)
    {
        for (int j = 0; j < repeat_time; j++)
        {
            putchar(ch);
        }
        putchar('\n');
    }

    return;
}
int main(void)
{
    int i = 0;
    int j = 0;
    char ch = 0;

    printf("Enter the character you want to print:");
    ch = getchar();
fflush(stdin);

    printf("Enter the number of times to print:");
    scanf("%d", &i);
fflush(stdin);

    printf("Enter the number of lines to print:");
    scanf("%d", &j);
    
fflush(stdin);
    print_n_char(ch, i, j);
    system("pause");
    return 0;

}