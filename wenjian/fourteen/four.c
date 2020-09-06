#include<stdio.h>
#include<stdlib.h>
struct name {
    char frist[32];
    char last[32];
    char mid[32];
};
struct four
{
    char number[32];
    struct name names;
};
void p4(struct four *member)
{
    for(int i = 0; i<5;i++)
    {
    printf("%s,%s",member[i].names.frist,member[i].names.last);
    if(member[i].names.mid[0] != '\0')
        printf("%s",member[i].names.mid);
    printf("--%s\n",member[i].number);
    }
}
void main(void)
{
    
    struct four member[5] = {
        {"302039823", {"Dribble", "FLossie", "M"}},
        {"302039824", {"Hello", "Kitty"}},
        {"302039285", {"Hello", "Jimmy", "J"}},
        {"302039286", {"Good", "Job"}},
        {"302039287", {"Jump", "High", "J"}}
    };

    p4(member);
    system("pause");
    return 0;
}