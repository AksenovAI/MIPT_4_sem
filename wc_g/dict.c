#include "dict.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Временная структура для сортировки
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordEntry;

// Функция сравнения для сортировки по убыванию
int compare_entries(const void* a, const void* b) {
    WordEntry* entry_a = (WordEntry*)a;
    WordEntry* entry_b = (WordEntry*)b;
    return entry_b->count - entry_a->count; // Сортировка по убыванию
}

struct dict* dict_create() {
    struct dict* new_dict = (struct dict*)calloc(1, sizeof(struct dict));
    new_dict->size = HASH_TABLE_SIZE;
    new_dict->words = (char**)calloc(new_dict->size, sizeof(char*));
    new_dict->counters = (int*)calloc(new_dict->size, sizeof(int));
    return new_dict;
}

void dict_destroy(struct dict* dict) {
    for (int i = 0; i < dict->size; i++) {
        if (dict->words[i]) {
            free(dict->words[i]);
        }
    }
    free(dict->words);
    free(dict->counters);
    free(dict);
}

int dict_hash_func(const char* word, int len) {
    unsigned long hash = 5381;
    for (int i = 0; i < len; i++) {
        hash = ((hash << 5) + hash) + word[i]; // hash * 33 + word[i]
    }
    return hash % HASH_TABLE_SIZE;
}

void dict_add(struct dict* d, const char* word, int word_len) {
    int key = dict_hash_func(word, word_len);

    // Поиск слова в хэш-таблице
    while (d->words[key] != NULL) {
        if (strcmp(d->words[key], word) == 0) {
            d->counters[key]++;
            return;
        }
        key = (key + 1) % HASH_TABLE_SIZE; // Линейное пробирование
    }

    // Добавление нового слова
    d->words[key] = (char*)calloc(word_len + 1, sizeof(char));
    strncpy(d->words[key], word, word_len);
    d->counters[key] = 1;
}

void dict_print(struct dict* d) {
    // Создаем массив для сортировки
    WordEntry* entries = (WordEntry*)calloc(d->size, sizeof(WordEntry));
    int entry_count = 0;

    // Собираем все слова и их счетчики в массив
    for (int i = 0; i < d->size; i++) {
        if (d->words[i] != NULL) {
            strncpy(entries[entry_count].word, d->words[i], MAX_WORD_LENGTH);
            entries[entry_count].count = d->counters[i];
            entry_count++;
        }
    }

    // Сортируем массив
    qsort(entries, entry_count, sizeof(WordEntry), compare_entries);

    // Выводим отсортированную таблицу
    printf("Слово\t\tКоличество\n");
    printf("----------------------------\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%s\t\t%d\n", entries[i].word, entries[i].count);
    }

    // Освобождаем память
    free(entries);
}