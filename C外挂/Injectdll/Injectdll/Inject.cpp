#include <Windows.h>

// 导出的函数，用于返回字符串
extern "C" __declspec(dllexport) LPCWSTR GetText()
{
    MessageBox(NULL,L"Hello from text.dll!",NULL,NULL);
    return;
}
