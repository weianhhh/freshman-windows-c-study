#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <algorithm>
#include <functional>
#define MAX 100
/*
1.创建数组基本语法
类型 数组名[数组长度]
	1.1数组长度: 一定要是常量;
	1.2 内存长相;
	1.3数组就是变量有规律内存连续的变量的集合
	1.4数组的最大下标:数组长度-1
2.数组的初始化: {} ==> 复合数据
	2.1默认初始化
	2.2完整初始化的一个写法
*/


void testCreate()
{
	//类型 数组名[数组长度];
	int arr[5] = {1,2};
	/*vs不支持 int nubmer = 5;
	int array[number];*/
	int array[] = { 1,2,3,4,5 };//自动推到数组长度为5
	int arrayinit[4] = { 0 };//默认初始化为0
	int a = 1, b = 2;
	int data[4] = { a,b };
	//新手容易出错的写法
	//只有数组创建的时候才能用{}数据初始化
	//int db[4];
	//db[4] = { 1,2,3,4 }; <==错的;

}

void testVisited()
{
	int arr[5] = { 1,2,3,4,5 };
//#ifdef 0
//printf("%d\n", arr[0]);
//	printf("%d\n", arr[1]);
//	printf("%d\n", arr[2]);
//	printf("%d\n", arr[3]);
//	printf("%d\n", arr[4]);
//#endif // 0
	printf("请输入5个数字:");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d",&arr[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void insertData(int arr[], int* curSize, int data)
{
	//放东西进去要考虑满的状态
	if (*curSize >= 100)
	{
		printf("满了,无法插入!");
		return;
	}
	//直接插入
	/*int pos = *curSize;
	arr[pos] = data;
	*curSize = pos + 1;*/
	//有序插入===>调整
	int pos = *curSize;
	arr[pos] = data;
	for (int k = pos; k > 0; k--)
	{
		if (arr[k] < arr[k -1])
		{
			int temp = arr[k];
			arr[k] = arr[k - 1];
			arr[k - 1] = temp;
		}
		else
		{
			break;
		}
	}
	*curSize = pos + 1;
}

void printData(int arr[], int curSize)
{
	for (int i = 0; i < curSize; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

//删除: 指定位置删除
//用数据对比做删除
void deleteByPos(int arr[], int* curSize, int index)
{
	//删东西都需要考虑空的状态
	if (*curSize == 0)
	{
		printf("数组为空无法删除!\n");
		return;
	}

	//序号删除==> 序号的有效性
	if (index< 1 || index>*curSize)
	{
		printf("序号无效无法删除!\n");
		return;
	}
	int pos = index - 1;
	for (int i = pos; i < *curSize-1; i++)
	{//做数组下标与运算的时候，一定要考虑边界问题
		arr[i] = arr[i + 1];
	}
	*curSize -= 1;
}

int main()
{
	//testVisited();
	int arr[5] = { 4,2,5,1,3 };
	std::sort(arr,arr +5,std::less<int>());//greater<int>()//内置类型从大到小
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");

	int data[MAX] = { 0 };//容器大小
	int curSize = 0;//数组当前的存储用户的数据
	printf("------------------insert-------------------\n");
	while (true)
	{
		int temp = 0;
		scanf_s("%d",&temp);
		if (temp == 0)
			break;
		insertData(data, &curSize, temp);
	}
	printData(data, curSize);
	printf("-------------------delete-------------------\n");
	deleteByPos(data, &curSize, 2);
	printData(data, curSize);
	return 0;
}