#include <stdio.h>

void print_bit_byte(unsigned char num)
{
  printf("%c", (0b10000000 & num) ? '1' : '0');
  printf("%c", (0b01000000 & num) ? '1' : '0');
  printf("%c", (0b00100000 & num) ? '1' : '0');
  printf("%c", (0b00010000 & num) ? '1' : '0');
  printf("%c", (0b00001000 & num) ? '1' : '0');
  printf("%c", (0b00000100 & num) ? '1' : '0');
  printf("%c", (0b00000010 & num) ? '1' : '0');
  printf("%c", (0b00000001 & num) ? '1' : '0');
  printf("\n");
}

unsigned char change_bits(unsigned char num, int lflip, int rflip)
{
    unsigned int lbit = num & (1 << lflip);
    unsigned int rbit = num & (1 << rflip);
    
    if(lbit)
        num = num | (1 << rflip);
    else
        num = num & (~(1 << rflip));

    if(rbit)
        num = num | (1 << lflip);
    else
        num = num & (~(1 << lflip));

    return num;
}

int main()
{
    unsigned num;
    printf("Введите число: ");
    scanf("%i", &num);

    printf("Введите позицию 1: ");
    unsigned pos1;
    scanf("%i", &pos1);

    printf("Введите позицию 2: ");
    unsigned pos2;
    scanf("%i", &pos2);

    print_bit_byte(num);
    unsigned char new_num = change_bits(num, pos1, pos2);
    print_bit_byte(new_num);
    printf("New num: %d\n", new_num);
    return 0;
}
