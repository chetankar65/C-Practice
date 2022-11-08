#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define BUFSIZE 100
#define MAXVAL 100
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            
            case '+':
                push(pop() + pop());
                break;
            
            case '*':
                push(pop() * pop());
                break;
            
            case '-':
                op2 = pop();
                push(pop() - op2);
                break; 
            
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;

            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push( (int) pop() % (int) op2);
                else
                    printf("Error");
                break;
            
            case '\n':
                printf("\t%.8g\n", pop());
                break;

            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}
/*
void printTop(void)
{
    return val[sp];
}

void duplicateTop(void)
{
    double dupl = val[sp];
    val[++sp] = dupl;
}

void swap()
{
    double temp = val[sp];
    double temp1 = val[--sp];
    val[--sp] = temp;
    val[sp] = temp1;
}
*/

double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';
    
    i = 0;

    if(!isdigit(c) && c != '.' && c != '-')
        return c;

    if(c == '-')
        if(isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else
        {
            if(c != EOF)
                ungetch(c);
            return '-';
        }
    
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;

    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);

    printf("%s", s);

    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
