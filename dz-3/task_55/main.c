#include <stdio.h>
#include <stdlib.h>

void print_bit_byte(unsigned char aByte)
{
  printf("%c", (0b10000000 & aByte) ? '1' : '0');
  printf("%c", (0b01000000 & aByte) ? '1' : '0');
  printf("%c", (0b00100000 & aByte) ? '1' : '0');
  printf("%c", (0b00010000 & aByte) ? '1' : '0');
  printf("%c", (0b00001000 & aByte) ? '1' : '0');
  printf("%c", (0b00000100 & aByte) ? '1' : '0');
  printf("%c", (0b00000010 & aByte) ? '1' : '0');
  printf("%c", (0b00000001 & aByte) ? '1' : '0');
  printf("\n");
}

int main()
{
    printf("Enter num: ");
    unsigned int temp;
    scanf("%i", &temp);

    unsigned char num = temp;
    print_bit_byte(num);

    unsigned char new_num = num << 1 | num >> 7;
    print_bit_byte(new_num);

    printf("New num: %d\n", new_num);
    return 0;
}
