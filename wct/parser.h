#pragma once

struct parser{
    char* buffer;
    char* cur_word;
};

char* parser_get_word_by_id(struct parser* txt, int id);
int parser_get_total_count(struct parser* txt);
int parser_parser(struct parser* txt);
int parser_read_from_descriptor(FILE* file);
int parser_parse(struct parser* txt);
int parser_destrioy(struct parser* par);