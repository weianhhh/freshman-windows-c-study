#include <Windows.h>

// �����ĺ��������ڷ����ַ���
extern "C" __declspec(dllexport) LPCWSTR GetText()
{
    MessageBox(NULL,L"Hello from text.dll!",NULL,NULL);
    return;
}
