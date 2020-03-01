#include <stdio.h>

int main()
{
	// Создаём таблицу
    char table[8][8];
    
    // Т.к. table двумерный массив, то и счётчиков два
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
        	// Собственно сам алгоритм заполнения таблицы
            if(i % 2 == 0)
            {
                if(j % 2 == 0)
                   table[i][j] = 'O';
                else
                   table[i][j] = 'X'; 
            }
            else
            {
                if(j % 2 == 0)
                    table[i][j] = 'X';
                else
                    table[i][j] = 'O';
            }
        }
    }

    // Вывод 
    printf("Ваша шахматная доска 8x8:\n");
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
            printf("%c ", table[i][j]);
        printf("\n");
    }

    return 0;
}
