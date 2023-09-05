#include <stdio.h>
#include <string.h>
class A {
	int n;
public:
	virtual void show() { printf("A类的show!\n"); }
	

private:

};
class B :public A {
public:
	void show() { printf("B类的show()!\n"); }


private:

};
class C :public A {
public:
	void show() { printf("C类的show()!\n"); }


private:

};


int main() {
	A a; B b; C c;
	printf("sizeof A : %d\n",sizeof(a));
	printf("sizeof B : %d\n", sizeof(b));
	printf("sizeof C : %d\n", sizeof(c));
	int* p = (int*)&a;
	printf("p->%p\n", p);
	printf("_vfptr->%p", *p);
	printf("show:%p\n",*(int*)*p);
	while (1)
	{

	}return 0;
}