#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ALLOCSIZE 10000

char *alloc(int n);
void afree(char *p);

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; /// pointing to the beginning of the 

int main()
{
    alloc(7);
    afree(allocp);
}

// 
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        printf("Allocated! \n");
        return allocp - n; /* old p */

    } else  
        return 0;
}

void afree (char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
        printf("Freed \n");
}
