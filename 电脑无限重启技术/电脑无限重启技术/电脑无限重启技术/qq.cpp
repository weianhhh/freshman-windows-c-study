#include <Windows.h>
#include <stdio.h>

//�����ѵĵ�����������
int main()
{
	//Ҫ��ʵ��<==����������
	//����ע���<==Window8s�ǳ���Ҫ�Ķ��� ��regedit��
	//������==>"HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\run"
	//ie��Main==>"HKEY_CURRENT_USER\SOFTWARE\Microsoft\Internet Explorer\Main"
	HKEY hKey;
	RegOpenKeyEx(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\run", 0, KEY_ALL_ACCESS, &hKey);
	TCHAR szInfo[260] = L"�ɵ�����,������������";
	RegSetValueEx(hKey,L"���������������",0,REG_SZ,(BYTE *)szInfo,260);
	return 0;
}