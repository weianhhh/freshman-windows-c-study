#include <stdio.h>
#include <windows.h>
//����
void PressKey(BYTE vkey)
{	
	//��3������flag:����0,����2��
	keybd_event(vkey, 0, 0, 0);
	Sleep(50);
	keybd_event(vkey, 0, 2, 0);
	Sleep(50);//ms
}
//˫��
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
	HWND hWnd;//����һ�����ڵľ��
	hWnd = FindWindow(L"ChatWnd", L"�ļ���������");//���㴰�� FindWIndow
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
		//��ϼ� 
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
//	SendMessage(hWnd,WM_PASTE,0,0);//��һ�����ڷ���ָ��;ճ��<==WM_PASTE
//	SendMessage(hWnd, WM_KEYDOWN, VK_RETURN, 0);//<==�������س�
//}
//printf("hello world!");