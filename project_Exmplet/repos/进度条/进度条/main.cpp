#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
void proc()
{
	string str("��");
	for (int i = 0; i <= 20; i++)
	{
		system("cls");
		cout << str << endl;
		cout << i*5 << "%" << endl;
		str += "��";
		Sleep(500);
	}

}
//���ȿ� ===> ��

int main()
{
	proc();
	cout << "��½�ɹ�!" << endl;
	system("pause");
	return 0;
}