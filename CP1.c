#include <stdio.h>

int convert(int, short, char);
short quit();

int main()
{

    int n;
    char check;

    do
    {
        do
        {
            printf("Enter your whole positive number (up to 3999):\n");
            if (scanf("%d%c", &n, &check) != 2 || check != '\n')
            {
                printf("Invalid number\n");
            }
            else if(n < 1)
            {
                printf("This is not a whole positive number!\n");
            }
            else if(n > 3999)
            {
                printf("Too large!\n");
            }
            fflush(stdin);
        }while (n < 1 || n > 3999 || check != '\n');

        printf("\nYour number in Roman numerals:\n");

        n = convert(n, 1000, 'M');
        n = convert(n, 500, 'D');
        n = convert(n, 100, 'C');
        n = convert(n, 50, 'L');
        n = convert(n, 10, 'X');
        n = convert(n, 5, 'V');
        n = convert(n, 1, 'I');

    }while(quit());

    return 0;
}

int convert(int n, short a, char r)
{
    while (n >= a)
    {
        putchar(r);
        n = n - a;
    }
    return n;
}

short quit()
{
    char ans, check;

    printf("\n\nDo you want to convert another number?\nAnswer (y/n): ");
    scanf("%c%c", &ans, &check);

    if (check != '\n')
    {
        return 0;
    }
    switch (ans)
    {
        case 'y':
            return 1;
    
        default:
            return 0;
    }
}