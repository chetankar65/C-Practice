#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int main()
{
    int n, array[MAX], getint(int *);

    for (n = 0; n < MAX && getint(&array[n]) != EOF ; n++)
        printf("Index : %d , %d \n", n ,array[n]);
        ;
}

double getint(int *p)
{
    int c, sign;
    while (isspace(c = getchar()))
        ;
    
    if (!isdigit(c) && c != '+' && c != '-' && c != EOF)
        return 0;

    sign = c == '-' ? -1 : 1;
    if (c == '-' || c == '+')
        c = getchar();

    for (*p = 0; isdigit(c); c = getchar())
    {
        *p = 10 * *p + (c - '0');
    }

    
    *p *= sign;
    

    return c;
}
