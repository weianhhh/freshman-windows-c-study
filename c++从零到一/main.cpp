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
///*钩子注入*/
//
////设置全局钩子
//BOOL SetGlobalHook()
//{
//	g_hHook = ::SetWindowsHookEx(WH_GETMESSAGE, (HOOKPROC)GetMsgProc, NULL, 0);
//	if (NULL == g_hHook) {
//		return FALSE;
//	}
//	return TRUE;
//}
////钩子回调函数
//LRESULT GetMsgProc(int code, WPARAM wParam, LPARAM lparam)
//{
//	return ::CallNextHookEx(g_hHook, code, wParam, lparam);
//}
////卸载钩子
//BOOL UnsetGlobalHook()
//{
//	if (g_hHook)
//	{
//		::UnhookWindowsHookEx(g_hHook);
//	}
//}
//共享内存
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
	::MessageBox(NULL, L"按键了", L"caption", 0x00000002L);
	return CallNextHookEx(keyboardHook, code, wParam, lParam);//第一个参数一般可以为NULL
}

//在对应线程设置键盘钩子
void setHook(DWORD threadId)//需要hook的线程ID
{
	//hook其他进程中的线程
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc,NULL, threadId);//"mydll.dll"里实现了KeyboardProc
	//hook自身进程中的线程
	//hhook = SetWindowsHookEx(WH_KEYBOARDPROC,KeyboardProc,NULL,threadId);
}
int main()
{
	setHook(0);
	SetWindowsHookEx(WH_SYSMSGFILTER,NULL,NULL,0);
	IsAlreadyRun();

	return 0;
}