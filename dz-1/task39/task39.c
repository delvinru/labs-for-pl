#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Текущий год для вычисления возраста
#define YEAR 2021

struct Worker{
    char* surname;
    int birth;
    char* status;
    int pay;
    char* edu;
};

int main()
{
    struct Worker workers[40];
    // Псевдослучайное ядро рандома при каждом запуске программы
    srand(time(NULL));
    // Базы
    char* surnames[] = {"Иванов", "Петров", "Прокофьева", "Тинькофф", "Греф", "Селивёрстов", "Белов", "Махнова", "Васильенков", "Сидоров"};
    char* statuss[] = {"Ген.дир", "Программист", "Стажёр", "Рабочий", "Охранник", "Сис.админ", "Безопасник"};
    char* edus[] = {"Высшее", "Среднее"};
    // Пробегаемся по структурам
    for(int i = 0; i < 40; i++)
    {
    	// Просто каждому полю из структуры присваем своё случайное значение из баз
        workers[i].surname = surnames[rand()%10];
        workers[i].status = statuss[rand()%7];
        workers[i].edu = edus[rand()%2];
        workers[i].pay = rand()%50000;
        workers[i].birth = 1950 + rand()%50;
    }

    unsigned int counter = 0;
    // Выполняем условие задачи
    for(int i = 0; i < 40; i++)
    {
        if(YEAR - workers[i].birth > 60 )
        {
            printf("%s %d %s %d %s\n", workers[i].surname, workers[i].birth, workers[i].status, workers[i].pay, workers[i].edu);
            counter++;
        }
    }
    printf("Количество работников: %d\n", counter);
    return 0;
}
