#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <algorithm>
#include <functional>
#define MAX 100
/*
1.������������﷨
���� ������[���鳤��]
	1.1���鳤��: һ��Ҫ�ǳ���;
	1.2 �ڴ泤��;
	1.3������Ǳ����й����ڴ������ı����ļ���
	1.4���������±�:���鳤��-1
2.����ĳ�ʼ��: {} ==> ��������
	2.1Ĭ�ϳ�ʼ��
	2.2������ʼ����һ��д��
*/


void testCreate()
{
	//���� ������[���鳤��];
	int arr[5] = {1,2};
	/*vs��֧�� int nubmer = 5;
	int array[number];*/
	int array[] = { 1,2,3,4,5 };//�Զ��Ƶ����鳤��Ϊ5
	int arrayinit[4] = { 0 };//Ĭ�ϳ�ʼ��Ϊ0
	int a = 1, b = 2;
	int data[4] = { a,b };
	//�������׳����д��
	//ֻ�����鴴����ʱ�������{}���ݳ�ʼ��
	//int db[4];
	//db[4] = { 1,2,3,4 }; <==���;

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
	printf("������5������:");
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
	//�Ŷ�����ȥҪ��������״̬
	if (*curSize >= 100)
	{
		printf("����,�޷�����!");
		return;
	}
	//ֱ�Ӳ���
	/*int pos = *curSize;
	arr[pos] = data;
	*curSize = pos + 1;*/
	//�������===>����
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

//ɾ��: ָ��λ��ɾ��
//�����ݶԱ���ɾ��
void deleteByPos(int arr[], int* curSize, int index)
{
	//ɾ��������Ҫ���ǿյ�״̬
	if (*curSize == 0)
	{
		printf("����Ϊ���޷�ɾ��!\n");
		return;
	}

	//���ɾ��==> ��ŵ���Ч��
	if (index< 1 || index>*curSize)
	{
		printf("�����Ч�޷�ɾ��!\n");
		return;
	}
	int pos = index - 1;
	for (int i = pos; i < *curSize-1; i++)
	{//�������±��������ʱ��һ��Ҫ���Ǳ߽�����
		arr[i] = arr[i + 1];
	}
	*curSize -= 1;
}

int main()
{
	//testVisited();
	int arr[5] = { 4,2,5,1,3 };
	std::sort(arr,arr +5,std::less<int>());//greater<int>()//�������ʹӴ�С
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");

	int data[MAX] = { 0 };//������С
	int curSize = 0;//���鵱ǰ�Ĵ洢�û�������
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