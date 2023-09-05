#include<stdio.h>
void main()
{
	int a = 5;
	_asm {
		mov eax,10
		mov a,eax
	}
	printf("%d",a);
}