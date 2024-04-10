#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex_number[18]; // Массив для хранения 16-ричного числа
    unsigned int decimal_number; // Переменная для хранения десятичного представления числа

    // Запрос ввода 16-ричного числа
    printf("Введите 16-ричное число: ");
    scanf("%16s", hex_number);

    // Преобразование 16-ричного числа в десятичное представление
    decimal_number = strtol(hex_number, NULL, 16);

    // Вывод десятичного представления числа со смещением на 1 бит вправо
    printf("Число со смещением на 1 бит вправо: %X\n", decimal_number >> 1);

    return 0;
}