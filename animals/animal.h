#pragma once
#include <stdlib.h>
struct animal{
    char* name;
    struct animal_m* met;
};
struct animal_m {
    void (*voice)(struct animal*);
};
struct animal* animal_create(char* name);
char* animal_get_name(struct animal* a);
void animal_set_name(struct animal* a, char* new_name);