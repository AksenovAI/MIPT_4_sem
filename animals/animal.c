#include "animal.h"

char* animal_get_name(struct animal* a){
    return a->name;
}

void animal_set_name(struct animal* a, char* new_name){
    a->name = new_name;
}

