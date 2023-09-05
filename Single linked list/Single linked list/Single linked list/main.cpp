#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
	int id;
	char name[20];
	int age;
};

struct singleList {
	struct student data;
	struct singleList* next;
};
//create table
struct singleList* createList()
{
	struct singleList* headNode = (struct singleList*)malloc(sizeof(struct singleList));
	headNode->next = NULL;
	return headNode;
}
//create node
struct singleList* createNode(struct student data)
{
	struct singleList* newNode = (struct singleList*)malloc(sizeof(struct singleList));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void insertNodeByHead(struct singleList* headNode, struct student data)
{
	struct singleList* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void printList(struct singleList* headNode)
{
	struct singleList* pMove = headNode->next;
	printf("编号\t姓名\t年龄\n");
	while (pMove)//pMove != NULL (void *)0
	{
		printf("%d\t%s\t%d\n",pMove->data.id, pMove->data.name, pMove->data.age);
		pMove = pMove->next;
	}
}
void saveInfoToFile(struct singleList* headNode, char* fileName) {}
void PrintMeau()
{
	printf("----------------------\n");
	printf("\t\t0.退出信息\n");
	printf("\t\t1.录入信息\n");
	printf("\t\t2.显示信息\n");
	printf("----------------------\n");
}
struct singleList* list = createList();
void keyDown()
{
	int choice = 0;
	scanf("%d",&choice);
	struct student tempData {};
	switch (choice)
	{
	case 0:
		system("pause");
		break;
	case 1:
		printf("请输入学生姓名,年龄,编号:");
		scanf("%d%s%d",&tempData.id, tempData.name, tempData.age);
		insertNodeByHead(list, tempData);
		break;
	case 2:
		printList(list);
		break;
	}
}
int main() {
	while (1) 
	{
		PrintMeau();
		keyDown();
		system("pause");
		system("cls");
	}
	return 0;
}