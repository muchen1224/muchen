#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    FILE *fp1;
    FILE *fp2;
    char n1[]={"D:\\code\\wenjian\\thirteen\\data1.txt"};
    if((fp1 = fopen(n1,"rb")) == NULL)
    {
        printf("file open failed");
    }
    fputc(n1,stdout);
    system("pause");
    return 0;

}