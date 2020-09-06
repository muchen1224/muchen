#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char ch = 0;
    int shu = 0;
    printf("«Î ‰»ÎASCII¬Î£∫");
    while((ch = getchar()) != '#')
    {
        if(shu % 8 == 0 && shu != 0)
        putchar('\n');
    }
    shu++;
    printf("%c:%d\n",ch,ch);
    system("pause");
    return 0;
}