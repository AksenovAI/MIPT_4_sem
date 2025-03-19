#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>






int main(int argv, char** argc){
    FILE* f = *fopen(argc[1], 'r');
    struct parser = parser_create();
    parser_read_from_descriptor(parser, f);
    parser_parse(parser);
    int total_count = parser_get_total_count(parser);
    struct dict = dict_create();
    


}