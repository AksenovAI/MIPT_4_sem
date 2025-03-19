#pragma once

#include <stdio.h>

struct parser {
    char* buffer;
    char* cur_word;
};

struct parser* parser_create();
void parser_destroy(struct parser* par);
int parser_read_from_descriptor(struct parser* p, FILE* file);
int parser_is_letter(char l);
int parser_parse(struct parser* p, FILE* src, struct dict* d);