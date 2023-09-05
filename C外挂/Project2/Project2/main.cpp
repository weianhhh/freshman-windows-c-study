#define WIN32_LEAN_AND_MEAU
#include <windows.h>
#include <stdio.h>
int main(void) {
	if (0 == FindWindow(NULL, L"н╒пе"))
		printf("wechat is Not running! please run game");
	else
		printf("Running...");
	exit(EXIT_SUCCESS);
}