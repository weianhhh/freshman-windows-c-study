#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

/*
bool example1(int data[],int n) {
	bool ret = false;
	for (int i = 0; i < n; i++)
	{
		if (data[i] < 0) {
			ret = true;
			printf("%d =%d\n",i,data[i]);
			//break;
			return true;
		}
	}
	return false;
}
int main(void)
{
	int data[100];
	memset(data, 0, sizeof(data));
	data[50] = -1;
	if (example1(data, 100)) {
		printf("有负数\n");
	}else{
		printf("没有负数\n");
	}
	return 0;
}*/
/*int main(void) {
	int m = 5;
	int days = 0;
	switch (m) {
	case 2:days = 28; break;

	case 1:
	case 3:
	case 5:
		days = 31; break;
	;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30; break;

	case 7:
	case 8:
	case 10:
	case 12:days = 31; break;	
	}
	printf("days=%d\n",days);
	return 0;
}*/
//int main(void) {
//	char a[1000000];
//	int n =1000000;
//	unsigned long long time1 = GetTickCount();
//	for (int i = 0; i < 100; i++)
//	{
//
//		for (int i = 0; i < n-1; i += 2)
//		{
//			a[i] = i + 1;
//			a[i + 1] = i + 2;
//		}
//		if (i == n - 1) {
//			a[i] = i + 1;
//		}
//	}
//	unsigned long long time2 = GetTickCount();
//	printf("%d %d %d\n", time2, time1 , time2 - time1);
//}
//struct vlaue {
//	int falg;
//	float num;
//};
//struct value data[100000];
//
//float vlaueGet(int index) {
//	if (data[index].flag == 0)
//	{
//		data[index].num = sqrt(index + 1);
//		data[index].flag = 1;
//	}
//	return data[index].num;
//}
//int main(void) {
//	memset(data, 0, sizeof(data));
//	return 0;
//}
/*
if ((a && !c) || a && b && c) {
kind = 1;
}*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "girl.h"
//class girl {
//private:
//	char name[32];
//	int age;
//	int  weight;
//	int height;
//	char* description = NULL;
//public:
//	char* getDescription() {
//		if (description == NULL)
//		{
//			char str[512];
//			sprintf(str, "姓名:%s\t年龄:%d\t身高:%d\t体体重:%d斤", name, age, height, weight);
//			description = (char*)malloc(strlen(str) + 1);
//			strcpy(description, str);
//		}
//		return description;
//	}
//	girl(const char* name, int age, int weight, int height) {
//		strcpy(this->name, name);
//		this->age = age;
//		this->weight = weight;
//		this->height = height;
//	}
//};
//
//int main() {
//
//	struct girl girl1("大美", 19, 120, 160);
//	struct girl girl2("小美", 18, 110, 170);
//	char* str1 = girl1.getDescription();
//	printf("%s\n", str1);
//
//	char* str2 = girl2.getDescription();
//	printf("%s\n", str2);
//
//	free(str1);
//	free(str2);
//
//	return 0;
//}
int main() {

	struct girl girl1 = { "大美",19,120,160 };
	struct girl girl2 = { "小美",18,110,170 };

	char* str1 = getDescription(&girl1);

	printf("%s\n", str1);

	char* str2 = getDescription(&girl2);
	printf("%s\n", str2);

	free(str1);
	free(str2);

	return 0;
}