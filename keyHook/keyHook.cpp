#include <windows.h>
#include "keyHook.h"
LRESULT CALLBACK hookproc(int code, WPARAM wParam, LPARAM lParam){

	HWND hwnd = GetActiveWindow();
	if (NULL == hwnd) {
		hwnd = GetForegroundWindow();
		if (NULL == hwnd) {
			return CallNextHookEx(hHOok, code, wParam, lParam);
		}
	}
	char windowText[MAX_PATH] = { 0 };
	GetWindowTextA(hwnd,windowText,MAX_PATH);
	MessageBox(NULL,windowText, "��ȡ����title", NULL);
	MessageBox(NULL,"���Ӵ���","��̬��",NULL);
	return CallNextHookEx(hHOok, code, wParam, lParam);
}
bool installHook() {
	/*MessageBox(NULL, L"installHook", L"dll��", NULL);
	return true;*/
	hHOok =  SetWindowsHookEx(WH_KEYBOARD,hookproc,GetModuleHandleW(L"keyHook"),NULL);

	if (NULL == hHOok) {
		MessageBox(NULL, "installHook error", "dll��", NULL);
	}
	else {
		MessageBox(NULL, "installHook sucess", "dll��", NULL);
	}
	return true;
}

bool uninstallHook() {
	/*MessageBox(NULL, L"uninstallHook", L"dll��", NULL);*/
	return UnhookWindowsHookEx(hHOok);
}