#include <stdio.h>
#include <windows.h>
//单键
void PressKey(BYTE vkey)
{	
	//第3个参数flag:按下0,弹起2。
	keybd_event(vkey, 0, 0, 0);
	Sleep(50);
	keybd_event(vkey, 0, 2, 0);
	Sleep(50);//ms
}
//双键
void PressKey(BYTE vkey1, BYTE vkey2)
{
	keybd_event(vkey1, 0, 0, 0);
	Sleep(50);
	keybd_event(vkey2, 0, 0, 0);
	Sleep(50);
	keybd_event(vkey2, 0, 2, 0);
	Sleep(50);
	keybd_event(vkey1, 0, 2, 0);
	Sleep(50);
}
int main()
{
	HWND hWnd;//定义一个窗口的句柄
	hWnd = FindWindow(L"ChatWnd", L"文件传输助手");//顶层窗口 FindWIndow
	while (1) {
		SetForegroundWindow(hWnd);

		PressKey(VK_TAB);
		PressKey(VK_TAB);

		while (1) {
			PressKey(VK_DOWN);
			PressKey(VK_RETURN);
			if (hWnd != GetForegroundWindow())
				return -1;
		}
		//组合键 
		PressKey(VK_CONTROL, 'V');

		//send
		PressKey(VK_RETURN);
		//close
		PressKey(VK_ESCAPE);
	}
	return 0;
}



//for (int i = 0; i < 6; i++)
//{
//	SendMessage(hWnd,WM_PASTE,0,0);//往一个窗口发送指令;粘贴<==WM_PASTE
//	SendMessage(hWnd, WM_KEYDOWN, VK_RETURN, 0);//<==按键，回车
//}
//printf("hello world!");