//#include <iostream>
//#include <string.h>
//using namespace std;
//int main()
//{
//    cout << "Hi M\\//\"\'\'om\n";
//    char hello[] = "i' love china";
//    printf(hello);
//    return 0;
//}
#include <windows.h>
BOOL IsAlreadyRun()
{
	HANDLE hMutex = NULL;
	hMutex = CreateMutex(NULL, FALSE, L"TEST");
	if (hMutex)
	{
		if (ERROR_ALREADY_EXISTS == GetLastError()) {
			return TRUE;
		}
	}
	return FALSE;
	
}
///*����ע��*/
//
////����ȫ�ֹ���
//BOOL SetGlobalHook()
//{
//	g_hHook = ::SetWindowsHookEx(WH_GETMESSAGE, (HOOKPROC)GetMsgProc, NULL, 0);
//	if (NULL == g_hHook) {
//		return FALSE;
//	}
//	return TRUE;
//}
////���ӻص�����
//LRESULT GetMsgProc(int code, WPARAM wParam, LPARAM lparam)
//{
//	return ::CallNextHookEx(g_hHook, code, wParam, lparam);
//}
////ж�ع���
//BOOL UnsetGlobalHook()
//{
//	if (g_hHook)
//	{
//		::UnhookWindowsHookEx(g_hHook);
//	}
//}
//�����ڴ�
/*
#pragma data_seg("mydata")
HHOOK g_hHook = NULL;
#pragma data_seg()
#pragma commnet(linker,"/SECTION:mydata,RWS")
*/

HHOOK keyboardHook;

LRESULT CALLBACK KeyboardProc(
	_In_ int    code,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	::MessageBox(NULL, L"������", L"caption", 0x00000002L);
	return CallNextHookEx(keyboardHook, code, wParam, lParam);//��һ������һ�����ΪNULL
}

//�ڶ�Ӧ�߳����ü��̹���
void setHook(DWORD threadId)//��Ҫhook���߳�ID
{
	//hook���������е��߳�
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc,NULL, threadId);//"mydll.dll"��ʵ����KeyboardProc
	//hook��������е��߳�
	//hhook = SetWindowsHookEx(WH_KEYBOARDPROC,KeyboardProc,NULL,threadId);
}
int main()
{
	setHook(0);
	SetWindowsHookEx(WH_SYSMSGFILTER,NULL,NULL,0);
	IsAlreadyRun();

	return 0;
}