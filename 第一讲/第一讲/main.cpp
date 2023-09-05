#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdlib.h>
#define enter cout << endl
using namespace std;


void add(std::vector<int>& vec,int x)
{
	vec.push_back(x);
}
void print(int x)
{
	cout << x <<" ";
}
auto auto_for(std::vector<int> &vec)
{
	for (auto x : vec)
	{
		print(x);
	}
	
}
void show_Info(std::vector<int>& vec)
{
	cout << "CAPACITY:" << vec.capacity() << endl;
	cout << "SIZE:" << vec.size() << endl;
	auto_for(vec);
}
void sort_for(std::vector<int>& vec)
{
	sort(vec.begin(), vec.end()); enter;
	auto_for(vec); enter;
}
int main()
{
	
	vector<int> v(2,7);
	show_Info(v);

	vector<int> v1 = { 7,8 };
	show_Info(v1);
	
	cout << endl;
	//ШЅжи
	vector<int>  vec = { 1,1,2,2,3,3,4,4,5,5,6,6 };
	auto iter = unique(vec.begin(), vec.end());
	vec.erase(iter,vec.end());
	for_each(vec.begin(), vec.end(), print);
	for_each(vec.begin(), vec.end(), [&](int &x) { add(v, x); });
	for_each(vec.begin(), vec.end(), [&](int& x) { add(v1, x); });

	sort_for(v);
	sort_for(v1);

	
	return 0;
}