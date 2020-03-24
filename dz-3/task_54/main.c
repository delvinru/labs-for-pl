#include <stdio.h>
#include <stdlib.h>

void to_bin(int num)
{
    for(int i = 31; i >= 0; i--)
        printf(num >> i & 1 ? "1": "0");
    printf("\n");
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: %s number\n", argv[0]);
        exit(1);
    }
    to_bin(atoi(argv[1]));
    return 0;
}
