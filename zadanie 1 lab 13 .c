#include <stdio.h>

int main(void)
{
    FILE *in;
    char filename[100];
    int a, n = 0;
    double sum = 0;

    printf("Введите имя файла: ");
    scanf("%99s", filename);

    in = fopen(filename, "r");

    if (in == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    while (fscanf(in, "%d", &a) == 1) {
        sum += a;
        n++;
    }

    fclose(in);

    if (n > 0)
        printf("Среднее арифметическое: %.2f\n", sum / n);
    else
        printf("В файле нет целых чисел\n");

    return 0;
}