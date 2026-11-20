#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *in, *out;
    char filename[200], result[220];
    char *dot;
    double number;
    int n = 0;

    printf("Введите имя файла: ");
    scanf("%199s", filename);

    in = fopen(filename, "r");

    if (in == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    strcpy(result, filename);
    dot = strrchr(result, '.');

    if (dot != NULL)
        *dot = '\0';

    strcat(result, "_replace1.dat");

    out = fopen(result, "w");

    if (out == NULL) {
        printf("Ошибка создания файла\n");
        fclose(in);
        return 1;
    }

    while (fscanf(in, "%lf", &number) == 1) {
        n++;

        if (n % 2 == 0)
            number = 0;

        fprintf(out, "%.15g\n", number);
    }

    fclose(in);
    fclose(out);

    return 0;
}