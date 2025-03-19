#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define HASH_TABLE_SIZE 3571
#define MAX_WORD_LENGTH 128

struct dict {
    int size;
    char** words;
    int* counters;
};

struct dict* dict_create();
void dict_destroy(struct dict* dict);
void dict_add(struct dict* d, const char* word, int word_len);
void dict_print(struct dict* d);
int dict_hash_func(const char* word, int len);
