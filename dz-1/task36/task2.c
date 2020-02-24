#include <stdio.h>

// Описываем структуру
struct Mountains{
	char* name;
	int   height;
};

int main()
{
	// Инициализируем массив структур
	struct Mountains Mountain[15];
	// Открываем файл на чтение
    FILE *fp = fopen("m.txt", "r");
    // Проходимся по массиву структур
	for(int i = 0; i < 15; i++)
	{
        char name[80];
        int height;
        fscanf(fp, "%s - %d", name, &height);
        Mountain[i].name = name;
        Mountain[i].height = height;
        // Необходимые условия по задачи
		if(Mountain[i].height > 3000)
			printf("%s\n", Mountain[i].name);
	}
	// Закрываем поток файла
    fclose(fp);
	return 0;
}
