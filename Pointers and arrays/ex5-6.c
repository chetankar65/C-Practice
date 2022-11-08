#include <stdio.h>
#include <ctype.h>
#define MAX 1000

int atoiv2(char *s);
void itoav2(int n, char *s);
int getLine(char *s);

int main()
{
    char s[MAX] = "1234"; 
    char out[MAX];
    char line[MAX];

    itoav2(-1234, out);
    printf("ATOI: %d\n", atoiv2(s));
    printf("ITOA: %s\n", out);
}

int atoiv2(char *s)
{
    int n, sign;

    for( ; isspace(*s); s++)   /* skip white space */
        ;
    sign = (*s == '-')? -1:1;

    if(*s == '+' || *s == '-')
        s++;

    for(n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    
    return sign * n;
}

void itoav2(int n, char *s)
{
    int sign;
    char *t = s;
    
    if((sign = n) < 0)
        n = -n;

    do
    {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);

    if(sign < 0)
        *s++ = '-';
    *s = '\0';

    // reverse()

}

void reverse(char *s)
{
    int c;
    char *t;

    for(t = s + (strlen(s)-1); s < t; s++, t--)
    {
        c=*s;
        *s=*t;
        *t=c;
    }
}

int getLine(char *s)
{
    int c;
    char *t = s;
    while ((c = getchar()) != '\n')
    {
        *s++ = c;
    }

    if (c = '\n')
    {
        *s++ = '\n';
    }

    *s = '\0';

    return *s - *t;
}
