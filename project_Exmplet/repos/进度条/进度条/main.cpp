#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
void proc()
{
	string str("■");
	for (int i = 0; i <= 20; i++)
	{
		system("cls");
		cout << str << endl;
		cout << i*5 << "%" << endl;
		str += "■";
		Sleep(500);
	}

}
//进度块 ===> ■

int main()
{
	proc();
	cout << "登陆成功!" << endl;
	system("pause");
	return 0;
}