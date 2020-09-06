#include<stdio.h>
#include<stdlib.h>
#define ABS_VAL 0.000001
int main(void)
{
    char ch;
    float number1,number2;
    do
    {
    printf("Enter the operation of your choice:\n");
    printf("%-20s%-20s\n","a. add","s. subtract");
    printf("%-20s%-20s\n","m. multiply","d. divide");
    printf("%-20s\n","q. quit");
    if (scanf("%c",&ch) == 1 && ('a' == ch ||'s' == ch || 'm' == ch || 'd' == ch || 'q' == ch))
     {
        printf("Please enter the correct operation,please enter again!\n");
        
     }
    getchar();
    if('q' == ch)
    {
    printf("Bye!\n");
    return ch;
    }
    printf("Enter frist number:");
    while(scanf("%f",&number1) != 0)
     {
            char ch = 0;
            while ((ch = getchar()) != '\n')
            {
                putchar(ch);
            }
            printf(" is not an number.\n");
            printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
            break;
        }
       

        printf("Enter second number:");
        while (scanf("%f", &number2) != 1)
        {
            char ch = 0;
            while ((ch = getchar()) != '\n')
            {
                putchar(ch);
            }
            printf(" is not an number.\n");
            printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
        }
        getchar();
    switch(ch)
    {
        case 'a':
            printf("%f + %f = %f\n", number1, number2, (number1 + number2));
            break;

        case 's':
            printf("%f - %f = %f\n", number1, number2, (number1 - number2));
            break;

        case 'm':
            printf("%f * %f = %f\n", number1, number2, (number1 * number2));
            break;

        case 'd':
            //在阈值区间内，将输入值判断为零，要求重新输入
            while (number2 > -ABS_VAL && number2 < ABS_VAL)
            {
                printf("Enter a number other than 0:");
                while (scanf("%f", &number2) != 1)
                {
                    char ch = 0;
                    while ((ch = getchar()) != '\n')
                    {
                        putchar(ch);
                    }
                    printf(" is not an number.\n");
                    printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
                }
                getchar();
            }
            printf("%f / %f = %f\n", number1, number2, (number1 / number2));
            break;

        default:
            break;
    }
  

}while(1);

  system("pause");
    return 0;
}