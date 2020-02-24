#include <stdio.h>

//Объявляем структуру для хранения данных
struct persons
{
	char surname[64];
	int children;
	int married;
};

int main()
{
	// Открываем файл, не сделана проверку на пустое условие, т.к. 
	// считаем, что файл с данным именем всегда существует
	FILE *fp = fopen("table.txt", "r");
	//выделяем память под структуры, т.к. нам известно точное количество людей
	struct persons person[25];
	for(int i = 0; i < 25; i++)
	{
		//считываем данные из файла построчно
		fscanf(fp, "%s %d %d", person[i].surname, &person[i].children, &person[i].married);
		// проверка на необходимые условия задачи
		if(person[i].married && person[i].children)
			printf("%s имеет детей и женат/замужем\n", person[i].surname);
	}
	//закрываем поток файла
	fclose(fp);
	return 0;
}
