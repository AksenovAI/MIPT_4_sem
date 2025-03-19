#include "dict.h"
#include "parser.h"
struct parser* parser_create(){
    struct parser* new_parser = calloc(1, 4096);
    new_parser->buffer = calloc(1, 4096);
    new_parser->current_word = calloc(1, 128);
    return new_parser;
}

int parser_destrioy(struct parser* par){
    free(par-> buffer);
    free(par-> cur_word);
    free(par);
    return 0;
}

int parser_read_from_descriptor(struct prser p, FILE* file){
    read(file, p->data, 4096);
    return 0;
}

parser_is_letter(struct parser* p, int id){
    char l = p->data[id];
    if((65 <= l && l <= 90) || (97 <= l && l <= 122)) return 1
    else return 0;
}

int parser_parse(struct parser* p, FILE* src, struct dict* d){
    int i = 0;
    int cur_word_ct = 0;
    parser_read_from_descriptor(p, src);
    while (p->buffer[i] != EOF){
        if(parser_is_letter(p, i)){
            p->cur_word[cur_word_ct] = p->buffer[i];
            cur_word_ct ++;
        } else {
            if (cur_word_ct > 0){
                dict_add(d, p->cur_word, cur_word_ct);
                cur_word_ct = 0;
            }
        }
        i++;
        if(i = 4095){
            parser_read_from_descriptor(p, src);
            i = 0;
        }
    }
}
