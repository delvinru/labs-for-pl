#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(char* string)
{
    int l_brackets = 0;
    int r_brackets = 0;

    for(unsigned int i = 0; i < strlen(string); i++)
    {
       if(string[i] == '(')
          l_brackets++;
       if(string[i] == ')')
       {
           r_brackets++;
           if(r_brackets > l_brackets)
           {
               printf("True?: no\nIndex of error: %d\n", i);
               exit(0);
           }
       }
    }
    if(l_brackets != r_brackets)
        printf("True?: no\nAmount of left brackets: %d\n", l_brackets);
    else
        printf("True?: yes\n");
}

int main(int argc, char** argv)
{
    // Usage
    if (argc < 2)
    {
        printf("Usage: %s expression\n", argv[0]);
        exit(0);
    }
    check(argv[1]);
    return 0;
}
