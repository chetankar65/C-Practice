#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000

char alphabetsSmall[30] = "abcdefghijklmnopqrstuvwxyz";
int expand(char s[]);
void mgetline(char s[],int lim);

int main()
{
    char s[MAXLINE];
    mgetline(s, MAXLINE);

    if (expand(s) == 1)
    {
        printf("Expansion: %s \n", alphabetsSmall);
    } 

    printf("%s", s);
}

void mgetline(char s[],int lim)
{
    int i,c;
    i = 0;

    while ((c = getchar()) != '\n')
    {
        s[i] = c;
        i++;
    }

    if (c == '\n')
        s[i] = '\n';
        i++;
    
    s[i] = '\0';

}

int expand(char s[])
{
    int i = 0;

    while (s[i] != '\0')
    {
        // check whether it is in the format -c or -c-c or c-c1-c2 such that c1 > c and c2 > c1
        if (s[i] == '-')
        {
            if (i > 0 && i < (strlen(s) - 1))
            {
                if ((s[i + 1] > s[i - 1]) || (s[i + 2] > s[i + 1]))
                {
                    return 1;
                }

                else 
                {
                    return 0;
                }
            }
        }

        i++;
    }
}