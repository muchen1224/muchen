#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int is_within(char ch,char *string)
{
    int  number =strlen(string);
    for(int i = 0;i < number;i++)
    {
        if(ch == string[i])
        {
            return 1;
        }
    }
    return 0;
}
int main(void)
{
    char ch = 0,string[256];
    _Bool no =0;
    while(1)
    {           
    printf("please enter string:");
    fgets(string,256,stdin);//gets_s()函数不支持，编译器不支持
    printf("please enter charcter:");
    ch = getchar();
    getchar();
    if(ch = '.')
    {
    continue;
    }
    no = is_within(ch,string);
    if(no ==0)
    {
        printf("character %c is not within %s\n", ch, string);
    }
    else
        {
            printf("character %c is within %s\n", ch, string);
        }
    }
    system("pause");
    return 0;

}