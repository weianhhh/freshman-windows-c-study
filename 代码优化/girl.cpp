#pragma once
#pragma warning(disable:4996)
#include "girl.h"

char* getDescription(struct girl* g) {
    char str[512];
    sprintf(str, "����:%s\t����:%d\t���:%d\t������:%d��", g->name, g->age, g->height, g->weight);
    char* ret = (char*)malloc(strlen(str) + 1);
    strcpy(ret, str);
    return ret;
}