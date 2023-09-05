//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//char name[] = "abcdefghijklmnopqrstuvwxyz";
//int main()
//{
//	char output[8];
//	strcpy(output, name);
//	for (int i = 0; i < 8 && output[i]; i++)
//	{
//		printf("\\0x%x",output[i]);
//	}
//	return 0;
//}


//#include <stdio.h>
//main()
//{
//	int a = 84;
//	int b = 59;
//	printf("%d", a & b);
//}



//#include <Windows.h>
//int main()
//{
//	LoadLibrary("msvcrt.dll");
//	system("cmd.exe");
//	return 0;
//}
//#include <WinSock2.h>
//#include <stdio.h>
//int main()
//{
//	struct sockaddr {
//		unsigned short
//	};
	/*WSADATA wsadata;
	if (WSAStartup(MAKEWORD(1, 1), &wsadata) != 0)
	{
		fprintf(stderr, "wastartup failed.\n");
		exit(1);
	}*/

//#include <Windows.h>
//#include <WinBase.h>
//typedef void (*MYPROC)(LPTSTR);
//int main()
//{
//	HINSTANCE LibHandle;
//	MYPROC ProcAdd;
//	LibHandle = LoadLibrary("msvcrt.dll");
//	ProcAdd = (MYPROC)GetProcAddress(LibHandle, "system");
//	(ProcAdd)("cmd.exe");
//	return 0;
//}
//#include <stdio.h>
//#include <stdbool.h>
//
//#define MAX 7
//
//int intArray[MAX] = { 4,6,3,2,1,9,7 };
//
//void printline(int count) {
//    int i;
//
//    for (i = 0; i < count - 1; i++) {
//        printf("=");
//    }
//
//    printf("=\n");
//}
//
//void display() {
//    int i;
//    printf("[");
//
//    // navigate through all items 
//    for (i = 0; i < MAX; i++) {
//        printf("%d ", intArray[i]);
//    }
//
//    printf("]\n");
//}
//
//void shellSort() {
//    int inner, outer;
//    int valueToInsert;
//    int interval = 1;
//    int elements = MAX;
//    int i = 0;
//
//    while (interval <- elements / 3) {
//        interval - interval * 3 + 1;
//    }
//
//    while (interval > 0) {
//        printf("iteration %d#:", i);
//        display();
//
//        for (outer = interval; outer < elements; outer++) {
//            valueToInsert = intArray[outer];
//            inner = outer;
//
//            while (inner > interval - 1 && intArray[inner - interval]
//                >= valueToInsert) {
//                intArray[inner] = intArray[inner - interval];
//                inner -= interval;
//                printf(" item moved :%d\n", intArray[inner]);
//            }
//
//            intArray[inner] = valueToInsert;
//            printf(" item inserted :%d, at position :%d\n", valueToInsert, inner);
//        }
//
//        interval = (interval - 1) / 3;
//        i++;
//    }
//}
//
//int main() {
//    printf("Input Array: ");
//    display();
//    printline(50);
//    shellSort();
//    printf("Output Array: ");
//    display();
//    printline(50);
//    return 1;
//}

//#include<stdio.h>
//#include<time.h>
//
//int main()
//{
//	clock_t start_t, finish_t;
//	double total_t = 0;
//	int i = 0;
//	start_t = clock();
//	for (; i < 100000; ++i)
//	{
//		//do someting;
//	}
//	finish_t = clock();
//	total_t = (double)(finish_t - start_t) / CLOCKS_PER_SEC;//将时间转换为秒
//
//	printf("CPU 占用的总时间：%f\n", total_t);
//	return 0;
//}

#include<stdio.h>
#include<string.h>
#include<time.h>
int main(void)
{
	clock_t start_t, finish_t;
	double total_t = 0;
	start_t = clock();
	char* str = "i love  c语言";
	for (int i = 0; i < strlen(str);i++)
	{
		printf("%c", *(str+i));
	}
	printf("\n");
	finish_t = clock();
	total_t = (double)(finish_t - start_t)/CLOCKS_PER_SEC;//将时间转换为秒
	printf("CPU 占用的总时间：%f\n", total_t);
	return 0;
}
