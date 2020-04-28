#!usr/bin/env python3

def choose_append(arr):
    tmp = []
    for i, el in enumerate(arr):
        if (i+1)%3 == 0:
            tmp.append(el)
    return tmp

if __name__ == "__main__":
    # task 1
    arr_a = input("Введите элементы списка через пробел: ").split(" ")
    # task 2
    arr_b = sorted(arr_a)[:]
    # task 3.1
    arr_c = choose_append(arr_a)
    # task 3.2
    arr_d = arr_a[1::2]
    # task 4
    # Не совсем точно описано задание, т.к. указано выбрать "элементы"
    # по определённому правилу, начиная с 0, что это значит?
    # Я должен отсортировать именно элементы массива или же речь идёт о позиции элемента
    dict_a = dict(zip(arr_a[::2], arr_a[1::2]))
    # task 5
    arr_e = list(zip(arr_a[::3], arr_a[1::3], arr_a[2::3]))
    # output
    print(f"""
Task_1:   {arr_a}
Task_2:   {arr_b}
Task_3.1: {arr_c}
Task_3.2: {arr_d}
Task_4:   {dict_a}
Task_5:   {arr_e}""")
