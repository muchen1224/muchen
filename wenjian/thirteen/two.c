#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp1;
    FILE *fp2;

    int ch = 0;
    if((fp1 = fopen("D:\\code\\wenjian\\thirteen\\data1.txt","r")) == NULL);
    {
        printf("Can't open %s\n","D:\\code\\wenjian\\thirteen\\data1.txt");
    }
    if((fp2 = fopen("D:\\code\\wenjian\\thirteen\\data2.txt","r")) == NULL);
    {
        printf("Can't open %s\n","D:\\code\\wenjian\\thirteen\\data2.txt");
    }
    while(ch = fgetc(fp1) != EOF)
    {
        fputc(ch,fp2);
        putc(ch,stdout);
    }
    fclose(fp1);
    fclose(fp2);
    system("pause");
    return 0;

}