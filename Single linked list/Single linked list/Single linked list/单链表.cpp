/*

*/
#include <stdio.h>
#include <stdlib.h>

struct singleList {
	int data;
	struct singleList* next;
};
void Show(int data) {
	printf("%d\n",data);
}
int main()
{
	int iNUm = 1;
	int *pNUm = &iNUm;
	int sum = *pNUm;
	printf("%d\n",sum);
	int* p = (int*)malloc(sizeof(int));
	*p = 3;
	printf("%d\n", *p);
	struct singleList Node1 = { 1,NULL };
	struct singleList Node2 = { 2,NULL };
	struct singleList Node3 = { 3,NULL };
	Node1.next = &Node2;
	Node2.next = &Node3;
	Show(Node1.data);
	Show(Node2.data);
	Show(Node3.data);


	return 0;
}