#pragma once

struct dict{
    int size;
    char** words;
    int* counters;
};

struct dict* dict_create();
void dict_destroy(struct dict* dict);er* parser_create();
void dict_add(struct dict* d, char* word, int word_len);
void dict_print(struct dict* d);

