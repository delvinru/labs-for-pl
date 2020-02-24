#include <stdio.h>
#include <stdlib.h>
// Хочу чтобы при каждом запустке программы числа были "псевдослучайными"
// Поэтому "ядро" функции rand задаётся от времени
#include <time.h>

// Описываем структуру
struct Item{
    char *name;
    int count;
    int price;
    char *manuf;
    char *date;
};

int main()
{
	// Необходимо для генерации даты
    time_t rawtime;
    struct tm* timeinfo;
    // Различные базы
    char *name[] = {"Молоко", "Вода", "Сыр", "Творог"};
    char *manuf_name[] = {"Фабрика1", "Фабрика2","Фабрика3","Фабрика4"};
    
    // Понятно
    struct Item items[40];

    // "Случайное" ядро рандома
    srand(time(NULL));
    for(int i = 0; i < 40; i++)
    {
    	// Буффер
        char buffer[80];
        // Получаем случайные данные из базы
        items[i].name = name[rand()%4];
        items[i].count = rand()%10;
        items[i].price = 100 + rand()%200;
        items[i].manuf = manuf_name[rand()%4];
        // Типо генерируем дату, но мне было лень делать "случайную" поэтому так
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        // Записываем дату в буффер и кладём её в структуру
        strftime(buffer, 80 , "%d.%m.%y", timeinfo);
        items[i].date = buffer;
    }

    unsigned int counter = 0; 
    // Далее понятно из кода, выполняем необходимые условия задачи
    for(int i = 0; i < 40; i++)
    {
        if(items[i].count > 5)
        {
            printf("%s %i %i %s %s\n", items[i].name, items[i].count, items[i].price, items[i].manuf, items[i].date);
            counter++;
        }
    }
    printf("Количество товара: %d\n", counter);
    return 0;
}
