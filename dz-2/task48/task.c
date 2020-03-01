#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Создаём структуру student
struct student{
    char* name;
    int height;
};

int main()
{
	// Создаём файл с студентами
    FILE *fstudents = fopen("students.txt", "w");
    // Псевдослучайные числа каждый раз
    srand(time(NULL));

    struct student init[25];
    char temp_name[10] = "student_";

    // Создаём студентов
    for(int i = 0; i < 25; i++)
    {
    	// Этот финт ушами нужен, для генерации разных студентов
    	temp_name[8] = 48+rand()%10;
    	temp_name[9] = 48+rand()%10;
    	init[i].name = malloc(10);
    	strcat(init[i].name, temp_name);
    	init[i].height = 150 + rand()%51;
    	// Запись в файл
    	fwrite(&init[i], sizeof(struct student), 1, fstudents);
    }
    // 1 часть закончилась
    fclose(fstudents);


    // Теперь 2 часть, сортируем студентов
    FILE *source = fopen("students.txt", "r");
    struct student people[25];
    // Во-первых, считываем студентов
    for(int i = 0; i < 25; i++)
    	fread(&people[i], sizeof(struct student), 1, source);

    // Bubble sort для структур
    for(int i = 0; i < 25; i++)
    {
    	for(int j = 0; j < 25 - i - 1; j++)
    	{
    		if(people[j].height > people[j+1].height)
    		{
    			struct student temp;
    			temp = people[j];
    			people[j] = people[j+1];
    			people[j+1] = temp;
    		}
    	}
    }

 	// Вывод учеников
    for(int i = 0; i < 25; i++)
    	printf("Ученик: %s, Рост: %d\n", people[i].name, people[i].height);
    return 0;
}
