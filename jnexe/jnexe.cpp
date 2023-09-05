#define _CRT_SECURE_NO_WARNINGS     //这个宏定义最好要放到.c文件的第一行
#pragma warning(disable:4996)

#include <windows.h>
#include <stdio.h>
#include <iostream>
HHOOK g_hHook = NULL;
LRESULT GetMsgProc(int code, WPARAM wParam, LPARAM lParam)
{
	return ::CallNextHookEx(g_hHook,code,wParam,lParam);
}/*
void GetwindowsVersion()
{
    OSVERSIONINFOEX osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (!GetVersionEx((OSVERSIONINFO*)&osvi))
    {
        std::cerr << "Error: GetVersionEx failed." << std::endl;
    }

    std::cout << "Windows OS version: ";
    if (osvi.dwMajorVersion == 10 && osvi.dwMinorVersion == 0)
        std::cout << "Windows 10" << std::endl;
    else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 3)
        std::cout << "Windows 8.1" << std::endl;
    else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 2)
        std::cout << "Windows 8" << std::endl;
    else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 1)
        std::cout << "Windows 7" << std::endl;
    else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 0)
        std::cout << "Windows Vista" << std::endl;
    else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1)
        std::cout << "Windows XP" << std::endl;
    else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0)
        std::cout << "Windows 2000" << std::endl;
    else
        std::cout << "Unknown Version" << std::endl;

}

void getwinsysinfo()
{
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    printf("%-20s%d\n", "处理器掩码:", systemInfo.dwActiveProcessorMask);
    printf("%-20s%d\n", "处理器个数:", systemInfo.dwNumberOfProcessors);
    printf("%-20s%d\n", "处理器分页大小:", systemInfo.dwPageSize);
    printf("%-20s%d\n", "处理器类型:", systemInfo.dwProcessorType);
    printf("%-20s%p\n", "最大寻址单元:", systemInfo.lpMaximumApplicationAddress);
    printf("%-20s%p\n", "最小寻址单元:", systemInfo.lpMinimumApplicationAddress);
    printf("%-20s%d ", "处理器等级:", systemInfo.wProcessorLevel);
    printf("%-20s%d ", "处理器版本:", systemInfo.wProcessorRevision);

    while (1);
}*/

int main()
{
    /*GetwindowsVersion();
    getwinsysinfo();*/
	HMODULE hDll = NULL;
	BOOL bRet = FALSE;
	hDll = ::LoadLibrary(L"Dll1.dll");
    g_hHook = SetWindowsHookEx(WH_GETMESSAGE, (HOOKPROC)GetMsgProc, hDll, 0);
	if (g_hHook == NULL)
	{
		printf("Hook Failed!\n");
		system("pause");
		return -1;
	}
	else {
		printf("Hook Success!\n");
		system("pause");
	}
	::UnhookWindowsHookEx(g_hHook);
	printf("InHook!\n");
	system("pause");
	return 0;
}