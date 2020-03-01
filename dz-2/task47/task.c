#include <stdio.h>

int main()
{
    // Создаём нужный файл
    FILE *source = fopen("numbers.bin", "wb");
    for(int i = 0; i < 1000; i++)
          fwrite(&i, sizeof(int), 1, source);
    fclose(source);
    // Собственно читаем данный файл
    FILE *bin = fopen("numbers.bin", "rb");
    FILE *even = fopen("even.txt", "w");
    FILE *odd = fopen("odd.txt", "w");
    // Считываем весь файл
    while(!feof(bin))
    {
    	// Создаём временную переменную и читаем туда числа
        int temp;
        fread(&temp, sizeof(int), 1, bin);
        // Проверяем чётность/нечётность
        if(temp % 2 == 0)
            fprintf(even, "%d\n", temp);
        else
            fprintf(odd, "%d\n", temp);
    }
    // Закрываем потоки
    fclose(bin);
    fclose(even);
    fclose(odd);
    return 0;
}
