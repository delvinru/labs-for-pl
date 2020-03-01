#include <stdio.h>
#include <malloc.h>

#define numbers 1,2,3,-12,14,-23,-13,-100,89,-8,0

int main()
{
    // Создаём массив m
    float m[] = {numbers};
    // Новый массив n
    float *n;
    // Выделяем память под n
    n = (float*)malloc(sizeof(m));
    // Выполняем, то что необходимо по условию задачи
    for(unsigned int i = 0; i < sizeof(m)/sizeof(int); i++)
    {
        if( m[i] >= 0 )
            n[i] = m[i] / 3;
        else
            n[i] = m[i]*m[i];
    }
    for(unsigned int i = 0; i < sizeof(m)/sizeof(int); i++)
        printf("%.2f ", n[i]);
    free(n);
    return 0;
}
