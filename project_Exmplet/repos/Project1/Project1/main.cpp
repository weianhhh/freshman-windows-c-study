#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
class A{
public:
	virtual void show() { printf("A���show!\n"); }
	A();
	~A();

private:

};
class B :public A{
public:
	void show() { printf("B���show()!\n"); }
	B();
	~B();

private:

};
class C :public A {
public:
	void show() { printf("C���show()!\n"); }
	C();
	~C();

private:

};

C::C()
{
}

C::~C()
{
}

B::B()
{
}

B::~B()
{
}
A::A()
{
}

A::~A()
{
}


int main() {

	B b; C c;
	//printf("b->%p,c->%p\n", &b,&c);
	b.show();
	c.show();
	A* p;
	
	p = &b;
	//printf("p->%p", &p);
	p->show();
	p = &c;
	//printf("p->%p", &p);
	p->show();
	while (1)
	{

	}
	return 0;
}

#if 0
class Person
{
	//public:
	char name[20];
	int age;

public:
	void eat(const char* food) {
		printf("%d������%s��%s\n", age, name, food);
	}
	Person();
	~Person();

private:

};

Person::Person()
{
}

Person::~Person()
{
}

int main() {
	Person p;
	//strcpy(p.name,"��");
	char* pStr = reinterpret_cast<char*>(&p);
	//char* pStr = (char*)(&p);
	printf("pStr:->%p,&p->%p\n", pStr, &p);
	strcpy(pStr, "����");
	pStr += 20;
	*(int*)pStr = 18;
	//void (Person:: * ptr)() = &Person::eat;
	//(p.*ptr)();
	/*class Cat : private Person {
	public:
		void eat(const char* food) {
			printf("%d������%s��%s\n", age, name, food);
	}

	};*/

	p.eat("����");
	//p.eat(const_cast<char*>("����"));
	while (true)
	{

	}return 0;
}
#endif // 0

