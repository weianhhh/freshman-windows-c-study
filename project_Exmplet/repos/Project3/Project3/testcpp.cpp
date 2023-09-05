//#include <iostream>
//#include <cstdio>
//using namespace std;
//namespace 贺瑞航的后宫
//{
//	char girlFriendName1[20] = "Lisa1";
//	char girlFriendName2[20] = "Lisa2";
//	char girlFriendName3[20] = "Lisa3";
//}
//int main()
//{
//	using namespace 贺瑞航的后宫;
//	std::cout << girlFriendName2 << std::endl;
//	cout << 贺瑞航的后宫::girlFriendName1 << endl;
//	int num;
//	std::cin >> num;
//	std::cout << num << std::endl;
//	system("color 0a");
//	system("title 恶灵骑士的DOS");
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
	system("title 邮箱验证");
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
	string str("■");
	for (int i = 0; i <= 10; i++)
	{
		system("cls");
		cout << str << endl;
		cout << i * 8 + i*2 << "%" << endl;
		str += "■";
		Sleep(500);
	}

}

int main()
{
	setWindowsStyle();
	char username[20] = "";
	char password[6] = "";
	cout << "用户名:";
	cin >> username;
	cout << "密码:";
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
			cout << "密码过长" << endl;
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
			//弹出进度条
			proc();
			//播放音乐
			cout << "Music begin" << endl;
			//再播放音乐
			/*mciSendString("open 夏に花が散る - 羽肿.mp3 alias music", 0, 0, 0);
			mciSendString("paly music repeat",0,0,0);*/
			//system("start wmplayer.exe 夏に花が散る - 羽肿.mp3");
			PlaySound(TEXT("夏に花が散る - 羽肿.mp3"), NULL, SND_FILENAME | SND_ASYNC);
		}
		else
		{
			cout << "用户名密码错误!" << endl;
		}
	}
	else
	{
		cout << username << "不是邮箱"  << endl;
	}
	system("pause");
	return 0;
}