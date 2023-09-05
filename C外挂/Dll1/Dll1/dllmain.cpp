#include "pch.h"
#include "textdll.h"

#define TEXTDLL_EXPORTS

// 导出的函数，用于返回字符串
LPCWSTR GetText()
{
    return L"Hello from text.dll!";
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
