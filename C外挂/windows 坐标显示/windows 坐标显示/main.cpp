#include <iostream>
#include <Windows.h>
#include <string>
LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0 && wParam == WM_LBUTTONUP)  // ���̧���¼�
    {
        MOUSEHOOKSTRUCT* pMouseStruct = (MOUSEHOOKSTRUCT*)lParam;
        if (pMouseStruct != nullptr)
        {
            POINT pt = pMouseStruct->pt;
            HWND hWnd = WindowFromPoint(pt);

            if (hWnd != nullptr)
            {
                TCHAR title[256] = { 0 };
                GetWindowText(hWnd, title, sizeof(title) / sizeof(TCHAR));

                RECT rect;
                GetWindowRect(hWnd, &rect);

                std::cout << "����: " << title << std::endl;
                std::cout << "����: X = " << rect.left << ", Y = " << rect.top << std::endl;
                std::cout << "�ߴ�: ��� = " << rect.right - rect.left << ", �߶� = " << rect.bottom - rect.top << std::endl;
            }
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}
int main()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    HHOOK hMouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookProc, hInstance, 0);

    if (hMouseHook == NULL) {
        std::cerr << "�޷�������깳�ӣ�" << std::endl;
        return 1;
    }

    std::cout << "������ⴰ���Ի�ȡ��λ�úʹ�С�����س����˳�����" << std::endl;
    std::cin.ignore();  // �ȴ��û�����

    UnhookWindowsHookEx(hMouseHook);

    return 0;
}
