#pragma once
#include "animal.h"
#include <stdio.h>
struct cat {
    struct animal a;
};


void cat_voice(struct animal* c);
struct animal* cat_create(char* name);