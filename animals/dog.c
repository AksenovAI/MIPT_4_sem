#include "dog.h"
void dog_voice(struct animal* c){
    struct animal * a = (struct animal *)c;
    char* name  = animal_get_name(a);
    printf("Dog %s bark! \n", name);
}

struct animal* dog_create(char* name){
    struct animal_m* m_dog = calloc(sizeof(struct animal_m), 1);
    m_dog->voice = dog_voice;
    struct animal* dog = calloc(sizeof(struct dog), 1);
    dog -> name = name;
    dog -> met = m_dog;
}



