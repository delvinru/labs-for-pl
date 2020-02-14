#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int get_gcd(int a, int b)
{
	int c = a%b;
	if(c == 0)
		return b;
	return get_gcd(b, c);
}

int gcd(int n, char** argv)
{
	int num = get_gcd(atoi(argv[1]), atoi(argv[2]));
	for(int i = 3; i < n; i++)
		num = get_gcd(num, atoi(argv[i]));
	return num;
}

int main(int argc, char** argv)
{
	if(argc < 3)
	{
		printf("Usage: ./gcd a b c ...\nWhere a, b, c is numbers\n");
		exit(0);
	}
	printf("gcd: %d\n", gcd(argc, argv));
	return 0;
}