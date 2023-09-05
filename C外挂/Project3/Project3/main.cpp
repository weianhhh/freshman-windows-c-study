
#include <windows.h>
#include <stdio.h>
#define TITLE "н╒пе"
BOOL CALLBACK EnumWindowProc(HWND, LPARAM);

int bGameStatus = 0;

int main(void) {
	EnumWindows(EnumWindowProc, NULL);
	if (!bGameStatus) {
		printf("Game is not up,please up Game..\n");
	}
	else {
	
		printf("Game is up......\n");
	}
	exit(EXIT_SUCCESS);
}
BOOL CALLBACK EnumWIndowProc(HWND hwnd, LPARAM lParam)
{
	wchar_t windowTitle[100] = { 0 };
	GetWindowText(hwnd,windowTitle,100*sizeof(wchar_t));
	if (0 == strcmp((const char*)windowTitle, TITLE)) {
		bGameStatus = 1;
	}
	return TRUE;
}




//int main(void) {
//	if (0 == FindWindowEx(NULL,NULL,NULL, L"н╒пе"))
//		printf("wechat is Not running! please run game");
//	else
//		printf("Running...");
//	exit(EXIT_SUCCESS);
//}
