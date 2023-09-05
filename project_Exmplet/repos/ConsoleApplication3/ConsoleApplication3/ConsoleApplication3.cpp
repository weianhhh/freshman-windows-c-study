#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstring>
using namespace std;

void proc()
{
    string str("■");
    for (int i = 0; i <= 10; i++)
    {
        system("cls");
        cout << str << endl;
        cout << i * 10 << "%" << endl;
        str += "■";
        Sleep(500);
    }
}

int main()
{
    char password[7] = "";
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
    if (strcmp(password, "12345") == 0)
    {
        // 弹出进度条
        proc();
        // 播放音乐
        cout << "Music begin" << endl;
    }
    else
    {
        cout << "密码错误!" << endl;
    }
    system("pause");
    return 0;
}
