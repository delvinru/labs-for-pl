#include <stdio.h>
#include <stdlib.h>

int get_gcd(int a, int b)
{
    int c = a%b;
    if (c == 0)
        return b;
    return abs(get_gcd(b, c));
}

int get_lcm(int a, int b)
{
   int gcd = get_gcd(a, b);
   return abs(a*b)/gcd; 
}
int main(int argc, char** argv)
{
    if(argc < 3)
    {
        printf("Usage:%s a b\n", argv[0]);
        exit(0);
    }
    int gcd = get_gcd(atoi(argv[1]), atoi(argv[2]));
    int lcm = get_lcm(atoi(argv[1]), atoi(argv[2]));

    printf("GCD: %d\nLCM: %d\n", gcd, lcm);
    return 0;
}
