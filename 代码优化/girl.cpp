#pragma once
#pragma warning(disable:4996)
#include "girl.h"

char* getDescription(struct girl* g) {
    char str[512];
    sprintf(str, "姓名:%s\t年龄:%d\t身高:%d\t体体重:%d斤", g->name, g->age, g->height, g->weight);
    char* ret = (char*)malloc(strlen(str) + 1);
    strcpy(ret, str);
    return ret;
}