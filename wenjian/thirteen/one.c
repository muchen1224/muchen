#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int ch;
    FILE *fp;
    unsigned int count = 0;
    char file_name[256];
    printf("Enter the file name:");
    scanf("%s",file_name,256);
    if((fp = fopen(file_name,"r")) == NULL)
    {
        printf("Can't open %s\n",file_name);
    }
    while((ch = getc(fp)) != EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %1u chracters\n",file_name,count);
    system("pause");
    return 0;
}
