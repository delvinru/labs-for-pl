#include <stdio.h>
// Числа для массива
#define numbers 1,2,3,4,5,58,78,999,9999, -8

int main()
{
	// Объявляем массив arr
    int arr[] = {numbers};
    // Проверочный индекс
    int index = -1;

    printf("Исходный массив:\n");
    for(unsigned int i = 0; i < sizeof(arr)/sizeof(int); i++)
        printf("%d ", arr[i]);
   
    // Проверка на возрастание массива, т.е. каждый следующий должен быть больше текущего
    for(unsigned int i = 0; i < sizeof(arr)/sizeof(int) - 1; i++)
    {
        if(arr[i+1] > arr[i])
            continue;
        else
        {
            index = i+1;
            break;
        }
    }

    // Сообщаем пользователю о результате
    if(index == -1)
        printf("\nПоздравляем, массив является упорядоченным по возрастанию\n");
    else
        printf("\nК сожалению, массив не является упорядоченным по возрастанию\nПервый элемент, который нарушает последовательность: %d\n", arr[index]);
    return 0;
}
