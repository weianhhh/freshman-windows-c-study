#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}struct List {
	int size;
	struct Node* firstNode;
	struct Node* lastNode;
};
struct List* createlist() {
	struct List* list = (struct List*)malloc(sizeof(struct List));
	list->size = 0;
	list->firstNode = list->lastNode = NULL;
	return list;
}
//表头法插入

void insertNodeByHead(struct List* list, int data) {
	struct Node* newNode = createNode(data);
	if (list->firstNode == NULL) 
	{
		//list->firstNode = newNode;
		list->lastNode = newNode;
		//list->firstNode = newNode;
	}
	else 
	{
		list->firstNode->left = newNode;
		newNode->right = list->firstNode;
		//list->firstNode = newNode;
	}
	list->firstNode = newNode;
	list->size++;
}
//表尾法插入
void insertNodeBytail(struct List* list, int data)
{	
	struct Node* newNode = createNode(data);
	if (list->lastNode == NULL) {
		list->firstNode = newNode;
	}
	else {
		list->lastNode->right = newNode;
		newNode->left = list->lastNode;
	}
	list->lastNode = newNode;
	list->size++;
}
//定位插入法

void insertNodeByAppoin(struct List* list, int data, int posData)
{	
	if (list->size == 0)
	{
		printf("链表为NULL,无法插入！");
		return;
	}
	else if (list->firstNode->data == posData) {
		insertNodeByHead(list, data);
	}
	else {
		struct Node* posNode = list->firstNode->right;
		struct Node* posNodeLeft = list->firstNode;
		while (posNode != NULL&&posNode-> data != posData)
		{
			posNodeLeft = posNode;
			posNode = posNodeLeft->right;
		}
		if (posData == NULL) {
			printf("为找到指定位置，无法插入！\n");
			return;
		}
		else
		{
			struct Node* newNode = createNode(data);
			posNodeLeft->right = newNode;
			newNode->left = posNodeLeft;
			newNode->right = posNode;
			posNode->left = newNode;

		}
		{

		}
	}
}
int listSize(struct List* list)
{
	return list->size;
}
int emptyList(struct List* list)
{
	if (list->size == 0)
		return 0;
	else 
		return 1;

}

void printListByLeft(struct List* list) {
	if (list->size == 0)
		printf("无法打印，链表是NULL的!");
	else {
		struct Node* pMove = list->lastNode;
		while (pMove)
		{
			printf("%d\t", pMove->data);
			pMove = pMove->left;
		}
	}
	printf("\n");
}

void printListByRight(struct List* list) {
	if (list->size == 0)
		printf("无法打印，链表是NULL的!");
	else {
		struct Node* pMove = list->firstNode;
		while (pMove)
		{
			printf("%d\t",pMove->data);
			pMove = pMove -> right;
		}
	}
	printf("\n");
}
int main() {
	struct List* list = createlist();
	/*int n;
	scanf("%d",&n);
	for (int i = 1; i < n; i++)
	{
		insertNodeByHead(list,i);
		
	}*/
	insertNodeByHead(list,3);
	insertNodeByHead(list,2);
	insertNodeByHead(list,1);
	printListByLeft(list);
	printListByRight(list);
	insertNodeBytail(list,100);
	printListByLeft(list);
	printListByRight(list);
	insertNodeByAppoin(list,200,100);
	printListByLeft(list);
	printListByRight(list);
	system("pause");
	return 0;
}