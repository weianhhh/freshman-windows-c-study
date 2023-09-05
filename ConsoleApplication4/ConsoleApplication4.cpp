#include <stdio.h>
#include <iostream>

struct test {
	char a[2];
	double b;
	int c;
	short d[2];

};
struct test2 {
	char a;
	int c;
	struct test test1;
};
#pragma pack(1)//66666666666666666666666666666666666
struct test3 {
	char a;
	int b;	
	char c;
};
int main(void)
{
	struct test3 tmp3;
	tmp3.a = 0x11;
	tmp3.b = 0x55443321;
	tmp3.c = 0x67;
	struct test tmp;
	struct test2 tmp2;
	tmp2.a = 0x11;
	tmp2.c = 0x23456789;
	printf("%d\n",sizeof(tmp3));
	printf("%d\n",sizeof(struct test));
	int size = sizeof(tmp3);
	printf("%d\n", sizeof(struct test2));
	printf("%d\n", sizeof(tmp2));
	unsigned char* p = (unsigned char*)&tmp3;
	printf("%d\n",sizeof(p));
	for (int i = 0; i < size; i++)
	{
		printf("[%X]",*p);
		p++;
		
	}
	
	return 0;
}