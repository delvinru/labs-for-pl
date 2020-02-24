/*
	Код старался писать понятный, осмысленные имена переменных и т.п.
	Но могут быть и косяки, ведь у меня лапки ฅ^•ﻌ•^ฅ
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

// Структура из условия задачи
struct Marshrut{
    unsigned int number;
    char* start;
    char* end;
    unsigned int length;
};

// Прототипы функций, которые мне необходимы 
// Создать маршруты
void* create_way(struct Marshrut *ways, int* size);
// Найти максимальный маршрут и вывести информацию о нём
void  find_max  (struct Marshrut *ways);
// Отсортировать маршруты от меньшего к большему
void  sort_ways (struct Marshrut *ways, int* size);
// Найти маршрут по заданному пункту
void  show_ways (struct Marshrut *ways, int* size);

int main()
{
	// Создаю и сразу выделяю память на 10 ячеек стуктуры. Почему? Потому что так хочу и ещё создаётся буффер в 10 записей.
    struct Marshrut *ways;
    ways = (struct Marshrut*)malloc(10*sizeof(struct Marshrut));
    // Размер стурктуры
    int size = 1;

    // Базовые настройки программы
    // Код нечитабельный, поэтому советую запустить и посмотреть что будет
    int choice;
    printf("\e[1;32m[1]\e[0m Создать маршруты\n\e[1;32m[2]\e[0m Найти максимально длинный маршрут\n\e[1;32m[3]\e[0m Отсортировать маршруты\n\e[1;32m[4]\e[0m Вывод сведения о маршруте\n\e[1;32m[5]\e[0m Вывести это меню\n\e[1;31m[0]\e[0m Выход из программы\n");
    printf("Выберите пункт: [1-5] или введите [0] для завершения программы: ");
    scanf("%1d", &choice);
    // Читаю только одну цифру и забираю мусор из потока ввода
    scanf("%*c");

    while(choice != 0)
    {
    	// Собственно и скелет программы. Выбор влияет на действие в программе.
        switch(choice)
        {
             case 1:
             	// Не знаю это костыль или нет, но выглядит нормально. Суть вот в чём: когда я перевыделяю память в функции, 
             	// то мне нужно как-то вернуть новый указатель на структуры. Собственно вот что это делает.
	             ways = (struct Marshrut*)create_way(ways, &size);
                 break;
             case 2:
                 find_max(ways);
                 break;
             case 3:
                 sort_ways(ways, &size);
                 break;
             case 4:
                 show_ways(ways, &size);
                 break;
             case 5:
             	 printf("\e[1;32m[1]\e[0m Создать маршруты\n\e[1;32m[2]\e[0m Найти максимально длинный маршрут\n\e[1;32m[3]\e[0m Отсортировать маршруты\n\e[1;32m[4]\e[0m Вывод сведения о маршруте\n\e[1;32m[5]\e[0m Вывести это меню\n\e[1;31m[0]\e[0m Выход из программы\n");
    			 break;
             case 0:
                 exit(0);
             default:
                 break;
        }
        printf("Выберите пункт: [1-5] или введите [0] для завершения программы: ");
    	fflush(stdin);
        scanf("%1d", &choice);
        // Также чищю мусор, чтобы не было багов
        scanf("%*c");
    }
    // Чистим за собой
    free(ways);
    // Конец программы.
    return 0;
}

//complete
void* create_way(struct Marshrut *ways, int* size)
{
	printf("\e[1;32m[!]\e[0mЗаполните данные:\n");
    
    // Создаю необходимые переменные для записи в структуру
    char str[128];
    // Стартовая позиция для начало отсчёта от последней записи в структуре
    unsigned int start_point = *size;
    // start_point - 1 + 10 - ограничение на ввод 10 записей за раз
    for(int i = start_point - 1; i < start_point - 1 + 10; i++)
    {
    	// "Чистим" поток ввода
    	fflush(stdin);
    	printf("\e[1;32m[---------------]\e[0m\nНомер маршрута: ");
    	// Читаем в str и записываем в структуру
    	fgets(str, 128, stdin);
    	// Если номер маршрута пустой, то сбрасывать цикл. Значит, пользователь не хочет больше вводить данные маршрутов.
		if(str[0] == '\n')
    		break;
    	ways[i].number = atoi(str);

    	// Далее аналогично. поясню только за malloc(128)
    	// Нужно чтобы выделить память для строки start
    	fflush(stdin);
    	printf("Начальная точка: ");
    	ways[i].start = malloc(128);
    	fgets(ways[i].start, 128, stdin);

    	fflush(stdin);
    	printf("Конечная точка: ");
    	ways[i].end = malloc(128);
    	fgets(ways[i].end, 128, stdin);

    	fflush(stdin);
    	printf("Длина маршрута: ");
    	fgets(str, 128, stdin);
    	ways[i].length = atoi(str);
    	*size += + 1;

    	// Вообщем это формула, которая позволяет определить десяток записей. Если было сделано 10 записей, то "добавить" память.
        if( (*size - 1) != 0 && (*size - 1) % 10 == 0)
        {
            ways = (struct Marshrut*)realloc(ways, (*size - 1 + 10) * sizeof(struct Marshrut));
            printf("\e[1;93m[!]\e[0m Дополнительная память выделена\n");
        }
    }
    printf("\e[1;32m[+]\e[0m Маршруты созданы\n");
   	// Возврат новой ссылки на ways
    return ways;
}

//complete
void find_max(struct Marshrut *ways)
{
	// Если нет записей в структуре кидаем ошибку пользователю
	if(ways[0].number == 0)
	{
		printf("\e[1;31m[!]\e[0m Для начала создайте маршруты\n");
		return;
	}
	// Создаём максимальный маршрут
	struct Marshrut max_way;
	int i = 0;
	// Собственно алгоритм поиска максимальной длины. Пояснять не требуется.
	unsigned int max = -0xffffffff;
	while(ways[i].number)
	{
		if(ways[i].length > max)
		{
			max = ways[i].length;
			max_way = ways[i];
		}
		i++;
	}
	// Красивый вывод, ничего интересного
	printf("\e[1;32m[+]\e[0m Самый длинный маршрут: \e[1;31m%u\e[0m\n", max_way.number);
	printf("\e[1;32m#############\e[0m\n");
	printf("Номер маршрута: %u\nНачальная точка: %sКонечная точка: %sДлина маршрута: %u\n", max_way.number, max_way.start, max_way.end, max_way.length);
	printf("\e[1;32m#############\e[0m\n\n");
}


void sort_ways(struct Marshrut *ways, int* size)
{
	// Мне было лень что-то выдумывать, поэтому вот. Сортировка пузырьком. Ничего не обычного.
    for(int i = 0; i < *size - 1; i++)
	{
        for(int j = 0; j < *size - 2 - i; j++)
        {
            if(ways[j].number > ways[j + 1].number)
            {
                struct Marshrut temp;
                temp = ways[j+1];
                ways[j+1] = ways[j];
                ways[j] = temp;
            }
        }
    }

    // Вывод отсортированных структур
    for(int i = 0; i < *size - 1; i++)
        printf("\e[1;32m[---------------]\e[0m\nНомер маршрута: %u\nНачальная точка: %sКонечная точка: %sДлина маршрута: %u\n", ways[i].number, ways[i].start, ways[i].end, ways[i].length);
}

//complete
void show_ways(struct Marshrut *ways, int* size)
{
	// Буферные переменные
	int counter = 0;
	char buffer[128];
	printf("Введите название пункта: ");
	// Чистка потока ввода
	fflush(stdin);
	fgets(buffer, 128, stdin);

	// Пробегаемся по всем структурам и ищём то что нужно. Тоже ничего необычного. Всё понятно.
	for(int i = 0; i < *size - 1; i++)
    {
		if( strcmp(ways[i].start, buffer) == 0 || strcmp(ways[i].end, buffer) == 0 )
		{
			printf("\e[1;32m#############\e[0m\n");
			printf("Номер маршрута: %u\nНачальная точка: %sКонечная точка: %sДлина маршрута: %u\n", ways[i].number, ways[i].start, ways[i].end, ways[i].length);
			printf("\e[1;32m#############\e[0m\n\n");
			counter++;
		}
	}
	if(counter == 0)
		printf("Может этого пункта не существует или вы ошиблись при вводе пункта\nПопытайтесь снова!\n");
}