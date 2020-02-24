#include <stdio.h>
#include <string.h>

int main()
{
	// Подключение файлов, откуда тянуть информацию
	FILE *surname = fopen("surname.txt", "r");
	FILE *name = fopen("name.txt", "r");
	// Буферы куда будут складываться данные
	char buf_sur[128];
	char buf_name[128];
	// Собственно читаем, пока не закончим и выводим
	while(fgets(buf_sur, 128, surname))
	{
		fgets(buf_name, 128, name);
		buf_sur[strlen(buf_sur)-1] = '\0';
		printf("%s\a %s", buf_sur, buf_name);
	}
	// Закрываем файловые потоки
	fclose(surname);
	fclose(name);
	return 0;
}
