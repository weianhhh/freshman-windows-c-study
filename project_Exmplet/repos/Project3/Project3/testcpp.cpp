//#include <iostream>
//#include <cstdio>
//using namespace std;
//namespace ���𺽵ĺ�
//{
//	char girlFriendName1[20] = "Lisa1";
//	char girlFriendName2[20] = "Lisa2";
//	char girlFriendName3[20] = "Lisa3";
//}
//int main()
//{
//	using namespace ���𺽵ĺ�;
//	std::cout << girlFriendName2 << std::endl;
//	cout << ���𺽵ĺ�::girlFriendName1 << endl;
//	int num;
//	std::cin >> num;
//	std::cout << num << std::endl;
//	system("color 0a");
//	system("title ������ʿ��DOS");
//	system("mspaint");
//	system("calc");
//	system("pause");
//	system("notepad");
//	return 0;
//}

//#include <mmsystem.h>
//#pragma comment(lib,"wimm.lib")
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <regex>
using namespace std;

void setWindowsStyle()
{
	system("title ������֤");
	system("color 0a");
	system("mode con cols=40 lines=8");
}


bool CheckEmail(char* username)
{
	regex object("(\\w+)@(\\w+)(\\.(\\w+))+");
	/*************************************************/
	bool result = regex_match(username, object);
	return result;
}

void proc()
{
	string str("��");
	for (int i = 0; i <= 10; i++)
	{
		system("cls");
		cout << str << endl;
		cout << i * 8 + i*2 << "%" << endl;
		str += "��";
		Sleep(500);
	}

}

int main()
{
	setWindowsStyle();
	char username[20] = "";
	char password[6] = "";
	cout << "�û���:";
	cin >> username;
	cout << "����:";
	char key;
	int i = 0;
	while ((key = _getch()) != '\r')
	{
		if (i < 6)
		{
			password[i++] = key;
			putchar('*');
		}
		else
		{
			cout << "�������" << endl;
			system("pause");
			return 0;
		}
	}
	password[i] = '\0';
	cout << endl;
	if (CheckEmail(username))
	{
		
		if (strcmp(username, "hrh123@qq.com") == 0 || strcmp(password, "12345") == 0)
		{
			//����������
			proc();
			//��������
			cout << "Music begin" << endl;
			//�ٲ�������
			/*mciSendString("open �Ĥ˻���ɢ�� - ����.mp3 alias music", 0, 0, 0);
			mciSendString("paly music repeat",0,0,0);*/
			//system("start wmplayer.exe �Ĥ˻���ɢ�� - ����.mp3");
			PlaySound(TEXT("�Ĥ˻���ɢ�� - ����.mp3"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else
		{
			cout << "�û����������!" << endl;
		}
	}
	else
	{
		cout << username << "��������"  << endl;
	}
	system("pause");
	return 0;
}