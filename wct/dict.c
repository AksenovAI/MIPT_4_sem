#include "dict.h"
struct dict* dict_create(){
    struct dict* new_dict = calloc(1, 4096);
    new_dict->size = 4096;
    new_dict->counters = calloc(sizeof(int*), new_dict->size);
    new_dict->words = calloc(sizeof(char*), new_dict->size);
    return new_dict;
}

int dict_destroy(struct dict* dict){
    for(int i = 0; i < dict->size; i++){
        if (dict->words[i] == 0) continue;
        else {
            for(int j = 0; j < 5; j ++){
                if (dict->words[i][j] != 0) free (dict->words[i][j]);
                if (dict->counters[i][j] != 0) free (dict->counters[i][j]);
                free(dict->words[i]);
                free(dict->counters[i]);
            }
        }
    }
    free(dict);
}

int dict_char_to_id(char){
    if(char >= 65 && char <= 90) return char
    else                         return char - 32
}

int dict_hash_func(char* word, int len){
    int k = 117;
    int m = 3571;
    unistd long r = 0;
    int pow_buf = 1;
    for(int i = 0; i < len; i++){
        r += word[i]*pow_buf;
        pow_buf *= k;
    }
    return long % m;
}

int dict_add(struct dict* d, char* word, int word_len){
    int key = dict_hash_func(word, word_len);
    for(int k = 0; k < 5; k++){
        if(strcmp(word, d->words[key][k]) == 0){
            d->counttrs[key][k] = ++;
            return 0;
        }
    }
    if(d->words[key] == 0){
        d->words[key] = calloc(sizeof(char*),5);
        d->words[key][0] = calloc(sizeof(char),128);
        strcpy(d->words[key][0], word);
        d-counters[key] = calloc(sizeof(int),5);
        counters[key][0] = 1;
    } else {
        for(int j = 1; j < 5; j ++){
            if(d->words[key][j] == 0){
                d->words[key] = calloc(sizeof(char*),5);
                d->words[key][j] = calloc(sizeof(char),128);
                strcpy(d->words[key][j], word);
                d-counters[key] = calloc(sizeof(int),5);
                counters[key][j] = ++;
            }
        }
    }
    }
}
void dict_print(struct dict* d){
   
}