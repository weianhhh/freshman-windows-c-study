#include <iostream>
#include "Vector.h"
using namespace std;
using namespace yazi::stl;
int main()
{
	Vector<int>vec;
	for (int i = 1; i < 5; i++)
	{
		vec.push_back(i);
	}
	vec.show();
	vec.pop_back();
	vec.show();
	vec.reserve(16);
	vec.show();
	return 0;
}