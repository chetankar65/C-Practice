#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

// function declarations

double atof(char s[]);
void getLine(char s[]);

int main()
{
    char s[MAXLINE];

    getLine(s);

    double d = atof(s);
    printf("%.2f \n", d);

}

void getLine(char s[])
{
    int i, c;
    i = 0;

    while ((c = getchar()) != '\n')
    {
        s[i++] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';
}

double atof(char s[])
{
    double val, power, expower, result, exponentVal;
    int i, sign, exponentSign, j;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    /// check "e", exponential value
    if (s[i] == 'e')
    {
        i++;
    }

    exponentSign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (exponentVal = 0.0; isdigit(s[i]); i++)
        exponentVal = 10.0 * exponentVal + (s[i] - '0');

    j = 0;
    expower = 1.0;

    while (j < exponentVal)
    {
        expower *= 10;
        j++;
    }

    result = sign * val / power;

    if (exponentSign < 0)
        result = result / expower;
    else
        result = result * expower;

    return result;
}