#include "cat.h"
void cat_voice(struct animal* c){
    struct animal * a = (struct animal *)c;
    char* name  = animal_get_name(a);
    printf("Cat %s meow! \n", name);
}

struct animal* cat_create(char* name){
    struct animal_m* m_cat = calloc(sizeof(struct animal_m), 1);
    m_cat->voice = cat_voice;
    struct animal* cat = calloc(sizeof(struct cat), 1);
    cat -> name = name;
    cat -> met = m_cat;
}



