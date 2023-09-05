#include <stdio.h>
#include <stdlib.h>
struct doubleList
{
	int data;
	struct doubleList* front;
	struct doubleList* tail;
};
struct doubleList* createList()
{
	struct doubleList* headNode = (struct doubleList*)malloc(sizeof(struct doubleList));
	headNode->front = headNode->tail = headNode;
	return headNode;
}
struct doubleList* createNode(int data)
{
	struct doubleList* newNode = (struct doubleList*)malloc(sizeof(struct doubleList));
	newNode->data = data;
	newNode->front = NULL;
	newNode->tail = NULL;
	return newNode;
}
void insertNodeNyHeadOrTail(struct doubleList* headNode,int data)
{
	struct doubleList* newNode = createNode(data);
	{

	};
}
int main()
{
	
	return 0;
}