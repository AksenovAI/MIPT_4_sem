#pragma once
#include "animal.h"
#include <stdio.h>
struct dog {
    struct animal a;
};

void dog_voice(struct animal* c);
struct animal* dog_create(char* name);