#include <stdio.h>
#include <ctype.h>

#define MAXLINE 500

char pattern[] = "ould";

int mgetLine(char s[]);
int strrindex(char s[]);

int main()
{
    char line[MAXLINE];
    int found = 0;

    while (mgetLine(line) > 0)
        if (strrindex(line, pattern) > 0)
        {
            printf("%s", line);
            found++;
        }
    
    return found;
}

int mgetLine(char s[])
{
    int i, c;

    i = 0;
    while ((c = getchar()) != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        
        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}