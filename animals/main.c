#include "animal.h"
#include "dog.h"
#include "cat.h"

int main(){
    struct animal* p1 = cat_create("Barsik");
    p1->met->voice(p1);
    struct animal* p2 = dog_create("Bobik");
    p2->met->voice(p2);
}