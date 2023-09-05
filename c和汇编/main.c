#include <stdio.h>
#include <string.h>
//int cmpmax(int a,int b,int c,int ,...)
//{
//    if (a > 0&&b > 0 && c < 0)
//	{
//		return (a > b) ? a : b;
//	}
//	if (a > 0 && b > 0 && c > 0 && d < 0);
//	{
//		return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
//	}
//	if (a > 0 && b > 0 && c > 0 && d > 0)
//	{
//		return ((a > b) ? ((a > c) ? ((a > d) ? a : d) : ((c > d) ? c : d)) : ((b > c) ? ((b > d) ? b : d) : ((c > d) ? c : d)));
//	}	
//}
void printStr(int a) {
	printf("%d\n",a);		
	if (a < 50) {
		printStr(++a);
	}
}
//void addx(int a, int b, int* e) {
//	return *e = a + b;
//}
void PrintAdd(int* arrStart, int* arrEnd)
{
	int sum = 0;
	while (arrStart < arrEnd)
	{
		sum += *arrStart;
		arrStart++;
	}
	printf("%d", sum);
}
int main()
{
	//int nNmuber = cmpmax(1, 2,3,4);
	int nfalg = 0;
	printStr(0);
	char a[] = "abcdefg";
	printf("%s\n",a);

	int b[10] = { [5] = 10 };
	
	int c[] = { 1,2,3,4,5 };
	PrintAdd(c,&(*(c+5)));
	/*printf("%\n",&b[5]);
	int d[][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9} };
	int* p;
	p = c;
	printf("%p",&p);*/
	/*int nRet = 0;
	addx(1,2,&nRet);*/
	return 0;
}