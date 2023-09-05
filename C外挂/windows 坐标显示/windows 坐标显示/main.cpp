#include <iostream>
#include <Windows.h>
#include <string>
LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0 && wParam == WM_LBUTTONUP)  // 左键抬起事件
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

                std::cout << "窗口: " << title << std::endl;
                std::cout << "坐标: X = " << rect.left << ", Y = " << rect.top << std::endl;
                std::cout << "尺寸: 宽度 = " << rect.right - rect.left << ", 高度 = " << rect.bottom - rect.top << std::endl;
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
        std::cerr << "无法设置鼠标钩子！" << std::endl;
        return 1;
    }

    std::cout << "点击任意窗口以获取其位置和大小。按回车键退出程序。" << std::endl;
    std::cin.ignore();  // 等待用户输入

    UnhookWindowsHookEx(hMouseHook);

    return 0;
}
