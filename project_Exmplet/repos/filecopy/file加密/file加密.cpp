#include <iostream>
#include <cstdio>
using namespace std;
namespace ���𺽵ĺ�
{
	char girlFriendName[20] = "Lisa1";
	char girlFriendName[20] = "Lisa2";
	char girlFriendName[20] = "Lisa3";
}
int main()
{
	using namespace ���𺽵ĺ�;
	std::cout << girlFriendName << std::endl;
	cout << ���𺽵ĺ�::girlFriendName << endl;
	int num;
	std::cin >> num;
	std::cout << num << std::endl;
	system("pause");
	return 0;
}