// WindowsProject4.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "WindowsProject4.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT4));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT4);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
 
            // 创建一个红色实线画笔，宽度为 3
            HPEN hPen = CreatePen(PS_DASH, 1, RGB(0,0 ,255));
           /* 
                1. `CreatePen(int fnPenStyle, int nWidth, COLORREF crColor)`：
                    - `fnPenStyle`：画笔样式，例如：`PS_SOLID`（实线画笔）、`PS_DASH`（虚线画笔）、`PS_DOT`（点线画笔）等。
                    - `nWidth`：指定画笔宽度，以逻辑单位表示。
                    - `crColor`：画笔的颜色，使用 `RGB` 宏定义颜色，如 `RGB(255, 0, 0)` 定义红色。
                    - 返回：创建的画笔句柄。
            */
            HPEN hOldPen = static_cast<HPEN>(SelectObject(hdc, hPen));
            /* 
                 2. `SelectObject(HDC hdc, HGDIOBJ hgdiobj)`：
                    - `hdc`：设备环境的句柄，通过 `BeginPaint` 或其他函数获取。
                    - `hgdiobj`：要选定为设备环境的对象（如画笔、画刷、字体等）的句柄。
                    - 返回：被替换对象的句柄。请注意保存原始句柄，以便稍后恢复。
            */
            // 使用创建的画笔绘制矩形
            Rectangle(hdc,250, 250, 200, 200);
            /*
                3. `Rectangle(HDC hdc, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect)`：
                    - `hdc`：设备环境的句柄，通过 `BeginPaint` 或其他函数获取。
                    - `nLeftRect`：矩形左上角 x 坐标。
                    - `nTopRect`：矩形左上角 y 坐标。
                    - `nRightRect`：矩形右下角 x 坐标。
                    - `nBottomRect`：矩形右下角 y 坐标。
                    - 返回：如果绘制成功，返回非零值；如果失败，返回零。
            */
            // 恢复原始画笔并删除创建的画笔
            SelectObject(hdc, hOldPen);


            DeleteObject(hPen);
            /*
                 4. `DeleteObject(HGDIOBJ hObject)`：
                    - `hObject`：要删除的 GDI 对象句柄（如画笔、画刷、字体、位图等）。
                    - 返回：如果删除成功，返回非零值；如果失败，返回零。

            */
            /*以下是针对以上代码中使用的 GDI 函数的详细参数说明：
                在上述代码中，我们创建了一个红色实线画笔，宽度为 3，
                然后将该画笔选定到设备环境中，这样后续的绘图操作将使用我们创建的这个画笔。
                之后，我们使用 `Rectangle` 函数绘制了一个矩形，指定了矩形的左上角和右下角坐标。
                最后，我们恢复原始的画笔并删除创建的画笔以避免内存泄漏。
            */            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
