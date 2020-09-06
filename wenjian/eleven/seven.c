#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *mystrncpy(char *s1,char *s2,int s)
{
    
  
    
   int n = strlen(s1);
    int m = strlen(s2);
    int q = (m >= s ? s:m);
    for(int a = 0;a <q;a++)
    {
        s1[n+a]=s2[a];
    }
    if(m<s)
    {
        s1[n+m]='\0';
    }
    return s1;
}
int main(void)
{
    char s1[256],s2[256];
    int n,m;
    while(1)
    {
    printf("please the s1:");
    fgets(s1,256,stdin);
     fflush(stdin);//未解决第一次输入时，缓存区存在的换行符
     
   
    printf("please the s2:");
    fgets(s2,256,stdin);
   
    fflush(stdin);
    n =strlen(s1);
    m =strlen(s2);
    //这两步用来求数组所占字数
    printf("the first original s1:");
    puts(s1);
    mystrncpy(s1,s2,256-n);
    printf("the second original s1:");
    puts(s1);
    }
    system("pause");
    return 0;
}