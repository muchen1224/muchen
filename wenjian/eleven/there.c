#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void input_(char *input)
{
    char ch =0;
    int i = 0;
    printf("enter the word:");
    do
    {
        ch = getchar();
        if(!isblank(ch))/* code */
        {
            break;
        }
    } while (1);
    input[i++] = ch;
    do
    {
            ch = getchar();
            if(isblank(ch))
            {
                break;
            }
            input[i++] =ch;                     
    } while (1);
    input[i] = '\0';
    return;
}
int main(void)
{
 char input[256];
 input_(input);
 printf("the word you entered is %s\n",input);
 system("pause");
 return 0;

}