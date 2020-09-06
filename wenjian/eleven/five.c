#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int strchr_(char *string,char *chr)
{
    int string_length = strlen(string);
    int chr_length = strlen(chr);
    int m = 0;
    int n = 0;
    for(int i =0;i<string_length;i++)
    {
        while(string[n] == chr[m])
        {
            n++;
            m++;
            if(m >= chr_length)
            {
                return i;
            }
        }
    }
    return -1;
}
int main(void)
{
    char string[256];
    char chr[256];
    int loc = 0;
    printf("enter the string:");
    gets_s(string,256);
    printf("Enter the string you want to find:");
    gets_s(chr,256);
    loc = strchr_(string,chr);
    if(-1 ==loc)
    {
        printf("%s does't appear in %s\n",chr,string);
    }
    else{
        printf("For  %s, it is staring from %d character in %s\n", chr, loc, string);
    }
    system("pause");
    return 0;
}