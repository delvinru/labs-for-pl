#include <stdio.h>
#include <string.h>

int main(int argc, const char** argv)
{
    if(argc == 1)
    {
        printf("Пожалуйста введите режим работы -r или -n\n");
        return 1;
    }
    // открываем необходимые файлы для работы программы
    FILE *source = fopen("1.txt", "r");
    FILE *output = fopen("2.txt", "w");

    // проверка на ошибки открытия файлов
    if(output == NULL || source == NULL)
    {
        printf("Произошла ошибка с открытием файла\n");
        return 1;
    }
    // Логика программы зависит от режимы который введёт пользователь
    // Если ключ -n, вывести в нормальном режиме, т.е. просто перенести в другой файл построчно
    
    // Стандартная вещь, ничего интересного
    if(strcmp(argv[1], "-n") == 0)
    {
        char buffer[256];
        while(fgets(buffer, 256, source))
            fprintf(output, "%s", buffer);
    }
    if(strcmp(argv[1], "-r") == 0)
    {
    	// Перемещаем указатель положения в файле на конец файла
        fseek(source, 0, SEEK_END);
        int size = 0;
        size = ftell(source);
        // Получили размер и можем работать
        char buffer[256];
        // Запускаем цикл со счётчикомо
        for(int i = 0; i < size; i++)
        {
        	// Перемещаемся по файлу по символьно
            fseek(source, size-i-1, SEEK_SET);
            char c = fgetc(source);
            // Если строка кончилась, то читаем строку и пишём в output
            if(c == '\n')
            {
                fgets(buffer, 256, source);
                fprintf(output, "%s", buffer);
            }
        } 
        // Читаем последнюю строку, перемещаем указатель на начало файла и читаем
        fseek(source, 0, SEEK_SET);
        fgets(buffer, 256, source);
        fprintf(output, "%s", buffer);
    }
    // Закрываем потоки
    fclose(source);
    fclose(output);

    return 0;
}
