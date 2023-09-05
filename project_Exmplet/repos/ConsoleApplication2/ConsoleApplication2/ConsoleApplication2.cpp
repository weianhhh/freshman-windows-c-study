#include <windows.h>
#include <winbase.h>

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR lpCmdline,int nShowCmd)
{
	// 此函数用于显示一个消息框，消息为"hello world"，标题为"caption"
	return 0;
}int main()
{
	AllocConsole();
	HWND consoleWnd = GetConsoleWindow();
	return MessageBox(NULL, L"hello world", L"caption", 0);
	FreeConsole();
}