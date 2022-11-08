/*take two separate inputs from user
TODO
*/

#include <stdio.h>
void squeeze(char line1[], char line2[]);
int size(char line[]);

int main()
{
    char line1[] = "Cprogram";
    char line2[] = "python";

    squeeze(line1, line2);

    printf("%s, %d\n", line1, size(line1));
}

void squeeze(char s1[], char s2[])
{
    int s1_len = size(s1);
    int s2_len = size(s2);

    int i, j, k;

    for (i = k = 0; i < s1_len; i++)
    {
        for (j = 0; j < s2_len; j++)
        {
            if (s1[i] == s2[j])
            {
                s1[i] = ' ';
            }
        }
    }
}

int size(char line[])
{
    int i = 0;
    while (line[i] != '\0')
    {
        i = i + 1;
    }

    return i;
}

