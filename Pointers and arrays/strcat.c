#include<stdio.h>
#define MAXLINE 1000

int mgetline(char line[],int maxline);
void mystrcat(char *,char *);
int mystrend(char *s, char *t);
int mystrlen(char *t);
int mystrncpy(char *s, char *t, int n);

int main(void)
{
    int len;
    char s[MAXLINE],t[MAXLINE];

    putchar('s');
    putchar(':');
    mgetline(s,MAXLINE);
    
    putchar('t');
    putchar(':');
    mgetline(t,MAXLINE);
    
    mystrcat(s,t);

    printf("%s",s);

    mystrend(s, t);

    if (mystrend(s, t) == 1)
        printf("Match! \n");

    return 0;
}

int mgetline(char s[], int lim)
{
    int c, i;
    
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';

    return i;
}

// s: abcd
// t : efgh
// n : 0123

void mystrcat(char *s, char *t)
{
    while(*s != '\0')
        s++;
    s--;             /* goes back to \0 char */

    while((*s = *t) != '\0')
    {   
        s++;
        t++;
    }
}

int mystrend(char *s, char *t)
{
    int len;
    len = mystrlen(t);
    while(*s != '\0')
        ++s;
    --s;

    while(*t != '\0')
        ++t;
            
    --t;

    while(len > 0)
    {
        if (*t == *s)
        {
            --t;
            --s;
            --len;
        }
        else
            return 0;
    }

    if (len == 0)
        return 1;
}

int mystrlen(char *t)
{
    char *p;
    p = t;

    while(*p != '\0')
        ++p;

    return p - t;
}
