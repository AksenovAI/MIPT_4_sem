#include "dict.h"
#include "parser.h"
#include <unistd.h>
#include <ctype.h>

struct parser* parser_create() {
    struct parser* new_parser = (struct parser*)calloc(1, sizeof(struct parser));
    new_parser->buffer = (char*)calloc(4096, sizeof(char));
    new_parser->cur_word = (char*)calloc(MAX_WORD_LENGTH, sizeof(char));
    return new_parser;
}

void parser_destroy(struct parser* par) {
    free(par->buffer);
    free(par->cur_word);
    free(par);
}

int parser_read_from_descriptor(struct parser* p, FILE* file) {
    size_t bytes_read = fread(p->buffer, 1, 4096, file);
    p->buffer[bytes_read] = '\0';
    return bytes_read;
}

int parser_is_letter(char l) {
    return isalpha(l);
}

int parser_parse(struct parser* p, FILE* src, struct dict* d) {
    int i = 0;
    int cur_word_ct = 0;

    while (1) {
        if (i >= 4096 || p->buffer[i] == '\0') {
            if (parser_read_from_descriptor(p, src) == 0) {
                break; // Конец файла
            }
            i = 0;
        }

        char current_char = p->buffer[i];
        if (parser_is_letter(current_char)) {
            p->cur_word[cur_word_ct++] = tolower(current_char);
        } else if (cur_word_ct > 0) {
            p->cur_word[cur_word_ct] = '\0';
            dict_add(d, p->cur_word, cur_word_ct);
            cur_word_ct = 0;
        }
        i++;
    }

    // Обработка последнего слова, если файл не заканчивается разделителем
    if (cur_word_ct > 0) {
        p->cur_word[cur_word_ct] = '\0';
        dict_add(d, p->cur_word, cur_word_ct);
    }

    return 0;
}