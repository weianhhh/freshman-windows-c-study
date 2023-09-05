#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct girl {
	char name[32];
	int age;
	int  weight;
	int height;
};
char* getDescription(struct girl* g);
	