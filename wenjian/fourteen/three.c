//图书目录
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * s_gets(char *st,int n)
{
    char * ret_val;
    char * find;
    ret_val=fgets(st,n,stdin);
    if(ret_val)
    {
        find=strchr(st,'\n');
         if(find)
            *find='\0';
         else
         {
            while(getchar != '\n')
                continue;
         }
        
    }
     return ret_val;
}
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 4
struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    printf("please enter the book title\n");
    printf("press [enter] at the start of a line to stop.\n");
    while(count<MAXBKS && s_gets(library[count].title,MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
        {
            continue;
        }
        if (count < MAXBKS)
        {
            printf("Enter the next title.\n");
        }
    }
    
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        printf("Array by original:\n");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        printf("\n");
        printf("Array by title:\n");
        for(int i = 0;i <count;i++)
        {
            for (int j = i; j < count; j++)
            {
                if(strcmp(library[i].title,library[j].title)>0)
                {
                    struct book tmp = library[i];
                    library[i] = library[j];
                    library[j] = tmp;
                }
            }
        }
       for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        printf("\n");

        printf("Array by value:\n");
        for (int i = 0; i < count; i++)
        {
            for (int j = i; j < count; j++)
            {
                if (library[i].value > library[j].value)
                {
                    struct book tmp = library[i];
                    library[i] = library[j];
                    library[j] = tmp;
                }
            }
        }
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        printf("\n");
    }
    else
        printf("No books? Too bad.\n");
    system("pause");

    return 0;
}
