#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE *in, *out;
    char filename[200], line[1024];
    int i, count = 0, in_word = 0;

    printf("Введите имя выходного файла: ");
    scanf("%199s", filename);

    in = fopen("winter.txt", "r");

    if (in == NULL) {
        printf("Ошибка открытия winter.txt\n");
        return 1;
    }

    out = fopen(filename, "w");

    if (out == NULL) {
        printf("Ошибка создания файла\n");
        fclose(in);
        return 1;
    }

    while (fgets(line, sizeof(line), in) != NULL) {
        for (i = 0; line[i] != '\0'; i++) {
            if (isspace((unsigned char)line[i])) {
                if (in_word && count % 3 == 0)
                    fputc('"', out);

                in_word = 0;
            } else if (!in_word) {
                in_word = 1;
                count++;

                if (count % 3 == 0)
                    fputc('"', out);
            }

            fputc(line[i], out);
        }
    }

    if (in_word && count % 3 == 0)
        fputc('"', out);

    fclose(in);
    fclose(out);

    return 0;
}