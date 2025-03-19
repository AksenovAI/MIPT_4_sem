#include "dict.h"
#include "parser.h"
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <файл>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    struct dict* dictionary = dict_create();
    struct parser* text_parser = parser_create();

    parser_parse(text_parser, file, dictionary);
    dict_print(dictionary);

    dict_destroy(dictionary);
    parser_destroy(text_parser);
    fclose(file);

    return 0;
}