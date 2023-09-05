// socket_test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
/*int main()
{
	void support();
	return 0;
}
void support()
{
	int num;
	printf("input a number:");
	scanf("%d",&num);
	(num % 2 == 0) ? printf("二叔") : printf("情书");
}*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
//#include <stdio.h>

/*void test()
{
	int i = 1, j;
	while (i <= 5)
	{
		j = 1;
		while (j <= i)
		{
			printf("*");
			j++;
		}
		printf("\n");
		i++;
		//printf("%d\n", i);
	}
}*/
/*
int main()
{
	int i = 5, j;
	while (i > 1)
	{
		j = 5;
		while (j > 1)
		{
			printf("");
			j--;
		}
		printf("\n");
		i--;
	}
	return 0;
}
void myarray(int *param)
{
	//形式参数是一个指针
}

void myarray(int param[10])
{
	//形式参数是一个已定义大小的数组
	//去掉10就是未定义的数组
}

double getarray(int arr[],int size)
{
	int i;
	double avg;
	double sum;
	for (i = 0;i < size;++i)
	{
		sum +=arr[i]
	}
	avg = sum /size;
	return avg;

}
*/


/* 函数声明 
double getAverage(int arr[], int size);

int main()
{
	//int* lenA;
	// 带有 5 个元素的整型数组 
	int balance[5] = { 1000, 2, 3, 17, 50 };
	//lenA = strlen(balance);
	printf("sizeof(balance) = %d\n", sizeof(balance));
	if (balance[5] == (int)balance[5])
	{
		printf("sizeof(balance[5]) = %d\n", sizeof(balance) / 4);
	}
	double avg;

	// 传递一个指向数组的指针作为参数 
	avg = getAverage(balance, 5);

	// 输出返回值
	printf("平均值是： %f ", avg);

	return 0;
}
double getAverage(int arr[], int size)
{
	int    i;
	double avg;
	double sum = 0;

	for (i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = sum / size;

	return avg;
}*/


/*int main()
{
	int n[10];
	int m[10][10] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8} };
	int h, k;
	for (int i = 1;;)
	{
		if (i++ <= 5)
		{
			for (int j = 1;;)
			{
				if (j++ <= 5)
				{	
					printf("*\n");
				}
				else
				{
					if (j-- >= 1)
					{
						for (i = 0 ;i <10;i++)
						{
							n[i] = i + 10;

							//printf("-");
						}
						for (j = 0; j < 10; j++)
						{
							printf("[%d]\n", n[j]);
						}
						for (h = 0; h < 10; h++)
						{
							for (k = 0; k < 10; k++)
							{
								printf("m[%d][%d] = %d\n", h, k, m[h][k]);
							}
						}
						
					}
					else
					{
						break;
					}
					break;
				}
			}
			printf("%d",i);
		}
		else
		{
			break;
		}
		printf("\n");
	}
	
	return 0;
}*/
//{
//	for (int i = 1;i <= 5; i++)
//	{
//		if (i == 5)
//		{
//			for (int j = 1;j <= 5;)
//			{
//				if (j == 5)
//				{
//					
//					printf("j");
//					
//				}
//				j++;
//				break;
//			}
//			
//			printf("i");
//			
//		}
//		
//		break;
//	}
//	return 0;
//}
//int main(void)
//{
//	int a[10] = { 0 };
//	if (a[10] is)
//}
// 
// 
//#include <stdio.h>
///*********************************
//* 方法1: 第一维的长度可以不指定
//*        但必须指定第二维的长度
//*********************************/
//void print_a(int a[][5], int n, int m) {
//	int i, j;
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < m; j++)
//			printf("%d ", a[i][j]);
//		printf("\n");
//	}
//}
///*****************************************
//* 方法2: 指向一个有5个元素一维数组的指针
//*****************************************/
//void print_b(int(*a)[5], int n, int m) {
//	int i, j;
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < m; j++)
//			printf("%d ", a[i][j]);
//		printf("\n");
//	}
//}
//
///***********************************
//* 方法3: 利用数组是顺序存储的特性,
//*       通过降维来访问原数组!
//***********************************/
//void print_c(int* a, int n, int m) {
//	int i, j;
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < m; j++)
//			printf("%d ", *(a + i * m + j));
//		printf("\n");
//	}
//}
//int main(void)
//{
//	int a[5][5] = { {1, 2}, {3, 4, 5}, {6}, {7}, {0, 8} };
//
//	printf("\n方法1:\n");
//	print_a(a, 5, 5);
//
//	printf("\n方法2:\n");
//	print_b(a, 5, 5);
//
//	printf("\n方法3:\n");
//	print_c(&a[0][0], 5, 5);
//
//	//    getch(); 
//	return 0;
//}
//
//#include<stdio.h>
//
//double outputs(float arr2[], int size);  //声明一个求平均数的函数
//
//int main()
//{
//	int k;
//	printf("你想求几个数的平均数：");
//	scanf("%d", &k);
//	float* arr1 = new float[k];            // 创建一个存放k个数的一维数组
//	for (int n = 0; n < k; n++)    // 使用 for 循环依次向数组添加元素
//	{
//		printf("请输入第%d个数：", n + 1);
//		scanf("%f", &arr1[n]);
//	}
//	printf("平均数为：%.4f\n", outputs(arr1, k));  // 向平均数函数赋值并输出结果（保留4位小数）
//}
//double outputs(float arr2[], int size)    // 定义平均数函数并传值
//{
//	double sum = 0;
//	for (int i = 0; i < size; i++)   // 使用 for 循环求和
//	{
//		sum += arr2[i];
//	}
//	return sum / size;       // 返回平均值
//}
//// 

//#include < iostream >
//using namespace std;
//int main(void)
//{
//	int len;
//	cin >> len;
//	int* array = new int[len];
//	int i = len;
//	while (i--) {
//		cin >> array[len];
//	}
//	for (int i = 0; i < len;i++) 
//	{
//		cout << array[i] << " ";
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//
//	enum day
//	{
//		saturday,
//		sunday,
//		monday,
//		tuesday,
//		wednesday,
//		thursday,
//		friday
//	}workday;
//		/*int* n = new n;
//		n = strlen(day);*/
//  //类型转换
//		//weekend = a; //错误
//		printf("sizeof(balance) = %d\n", sizeof(workday));
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int var_runoob = 10;
//	int* p;
//	p = &var_runoob;
//	printf("he in:%p\n", p);
//	printf("\n");
//	printf("var_runoob 变量的地址： %d\n", &p);
//	printf("p 变量地址： %d\n", &p);
//	
//	printf("\n");
//
//	printf("var_runoob 变量： %d\n", var_runoob);
//	printf("\n");
//
//	printf("var_runoob 变量地址： %d\n", &var_runoob);
//	printf("p变量： %d\n", p);
//	printf("\n");
//
//	printf("var_runoob p变量： %p\n", var_runoob);
//	printf("\n");
//
//	printf("var_runoob p变量地址： %p\n", &var_runoob);
//	printf("p变量： % p\n", p);
//	printf("\n");
//
//	printf("***************************************\n");
//	printf("\n");
//	
//	printf("\n");
//	printf(" p内存变量地址： %p\n", &p);
//	printf("\n");
//}
//#include <stdio.h>
//int main()
//{
//	int var = 20;
//	int* ip;
//	ip = &var;
//	printf("%p\n", var);
//	printf("%p\n",ip);
//	printf("%d\n",*ip);
//}

//#include <stdio.h>
//
//int main()
//{
//	int var = 20;
//	int* ptr = &var;
//	if (ptr)
//	{
//		printf("p 非空，则完成 ,ptr 的地址是 %p\n", ptr);
//	}
//	else if (!ptr)
//	{
//		printf("p 为空，则完成 ,ptr 的地址是 %p\n", ptr);
//	}
//	return 0;
//}
//#include <stdio.h>
//const int Max = 3;
//int main()
//{
//	int var[] = { 10,20,30 };
//	int i, * ptr;
//	ptr = &var[Max-1];
//	for (i = Max; i > 0; i--)
//	{
//		printf("var[%d] = %p\n", i, ptr);
//	
//		printf("var[%d] = %d\n",i,*ptr);
//		ptr--;
//	}
//	printf("********************\n");
//	for (i = Max; i > 0; i--)
//	{
//		printf("var[%d] = %d\n", i, ptr);
//
//		printf("var[%d] = %p\n", i, *ptr);
//		ptr--;
//	}
////}
//#include <stdio.h>
//const int Max = 3;
//int main()
//{
//	int var[] = { 10,100,1000 };
//	int i, *ptr;
//	ptr = var;
//	i = 0;
//	while (ptr <= &var[Max - 1])
//	{
//		printf("var[%d] = %p\n",i,ptr);
//		printf("var[%d] = %d\n",i,*ptr);
//		ptr++;
//		i++;
//	}
//}	
//#include <stdio.h>
//void main()
//{
//	int x = 4;
//	printf("%d\n", x);
//	int y = ++x > 5 ? 0 : 1;
//	printf("%d,%d\n", x, y);
//}
//#include <stdio.h>
//int max(int x, int y)
//{
//	return x > y ? x : y;
//
//}
//int main(void)
//{ 
//	int (*p)(int, int) = &max;
//	int a, b, c, d;
//	printf("");
//	scanf("%d %d %d", &a, &b, &c);
//	d = p(p(a, b), c);
//	printf("zuidashuzishi:%d\n", d);
//}
//#include <stdio.h>
//#include <stdlib.h>
//void p_array(int* array, size_t arrayszie, int (*getNetValue)(void))
//{
//	for (size_t i = 0; i < arrayszie; i++)
//	{
//		array[i] = getNetValue();
//	}
//}
//int getNextrandomvalue(void)
//{
//	return rand();
//}
//int main(void)
//{
//	int myarray[10];
//	p_array(myarray, 10, getNextrandomvalue);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n",myarray[i]);
//	}
//	printf("\n");
//	return 0;
//}
#include <stdio.h>
#include <stdbool.h>

#define MAX 7

int intArray[MAX] = { 4,6,3,2,1,9,7 };

void printline(int count) {
	int i;

	for (i = 0; i < count - 1; i++) {
		printf("=");
	}

	printf("=\n");
}

void display() {
	int i;
	printf("[");

	// navigate through all items 
	for (i = 0; i < MAX; i++) {
		printf("%d ", intArray[i]);
	}

	printf("]\n");
}

void shellSort() {
	int inner, outer;
	int valueToInsert;
	int interval = 1;
	int elements = MAX;
	int i = 0;

	while (interval <= elements / 3) {
		interval = interval * 3 + 1;
	}

	while (interval > 0) {
		printf("iteration %d#:", i);
		display();

		for (outer = interval; outer < elements; outer++) {
			valueToInsert = intArray[outer];
			inner = outer;

			while (inner > interval - 1 && intArray[inner - interval]
				>= valueToInsert) {
				intArray[inner] = intArray[inner - interval];
				inner -= interval;
				printf(" item moved :%d\n", intArray[inner]);
			}

			intArray[inner] = valueToInsert;
			printf(" item inserted :%d, at position :%d\n", valueToInsert, inner);
		}

		interval = (interval - 1) / 3;
		i++;
	}
}

int main() {
	printf("Input Array: ");
	display();
	printline(50);
	shellSort();
	printf("Output Array: ");
	display();
	printline(50);
	return 1;
}