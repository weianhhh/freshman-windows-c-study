// GDI绘图技术.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "GDI绘图技术.h"

#define MAX_LOADSTRING 100

#define Tank_Width 40
#define Tank_Height 40
//坦克
enum {UP,DOWN,LEFT,RIGHT};
typedef struct _Tank
{
    int x;
    int y;
    int direction;
}Tank;
typedef struct _Bullet
{
    int x;
    int y;
    int direction;
}Bullet;
typedef struct _BulletList
{
    Bullet bullet;
    struct _BulletList* next;
}BulletList;
BulletList* g_hend = NULL;

// 全局变量:
HINSTANCE hInst;                                // 当前实例
HWND g_hwnd;
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//init_Tank
void InitTank(Tank* tank);
void DrawTank(HDC hdc,Tank* tank);
void CreateBullet(Tank* tank ,BulletList* pHend);
void DrawBullet(HDC hdc,BulletList* pHend);
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);



    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GDI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GDI));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GDI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GDI);
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
   g_hwnd = hWnd;
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
    PAINTSTRUCT ps;

    HDC hdc = NULL;
    static Tank tank;
    g_hwnd = hWnd;
    switch (message)
    {
    case WM_CREATE:
        {
            InitTank(&tank);
            //SetTimer(hWnd,1,200,NULL);
        }
        break;
    /*case WM_TIMER:
        switch (wParam)
        {
        case 1:
            tank.y -= 5; tank.direction = UP;
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;*/
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
            /*Rectangle(hdc, 0, 0, 200, 200);
            Ellipse(hdc,0,0,200,200);
            MoveToEx(hdc,100,100,NULL);
            LineTo(hdc,300,200);*/

            //HPEN hPen1 = CreatePen(PS_SOLID,4,RGB(255,0,0));
            //HPEN hPen2 = CreatePen(PS_DASH, 1, RGB(0, 255, 0));
            //HPEN hPen3 = CreatePen(PS_DASHDOT,1, RGB(0, 0, 255));
            //LOGPEN logPen;
            //logPen.lopnStyle = PS_SOLID;
            //logPen.lopnWidth.x = 5;
            //logPen.lopnColor = RGB(255, 255, 0);
            //HPEN hPen5 = CreatePenIndirect(&logPen);
            //SelectObject(hdc,hPen5);
            //Rectangle(hdc, 10, 10, 100, 100);

            ///*SelectObject(hdc,hPen1);
            //Rectangle(hdc, 10, 10, 200, 200);
            //SelectObject(hdc, hPen2);
            //Rectangle(hdc, 100, 100, 200, 200);
            //SelectObject(hdc, hPen3);
            //Rectangle(hdc, 10, 10, 100, 200);*/

            //HBRUSH hBrush1 = CreateSolidBrush(RGB(128, 51, 255));
            //SelectObject(hdc,hBrush1);
            //Rectangle(hdc, 10, 10, 200, 200);
            DrawTank(hdc,&tank);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_SPACE:
            CreateBullet(&tank,g_hend);
            DrawBullet(hdc,g_hend);
            break;
        case VK_LEFT:
            tank.x -= 5; tank.direction = LEFT;
            break;
        case VK_RIGHT:
            tank.x += 5; tank.direction = RIGHT;
            break;
        case VK_UP:
            tank.y -= 5; tank.direction = UP;
            break;
        case VK_DOWN:
            tank.y += 5; tank.direction = DOWN;
            break;
        }
        InvalidateRect(hWnd,NULL,TRUE);
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
void InitTank(Tank* tank)
{
    RECT rect;
    GetClientRect(g_hwnd, &rect);
    tank->x = (rect.right - rect.left);
    tank->y = (rect.bottom - rect.top) - (Tank_Height) / 2;
    //deafult is up
    tank->direction = UP;
}

void DrawTank(HDC hdc,Tank* tank)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(255,238,114));
    HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
    Rectangle(hdc,tank->x-Tank_Width/2,tank->y-Tank_Height/2, tank->x + Tank_Width / 2, tank->y + Tank_Height / 2);
    switch (tank->direction)
    {
    case UP:
        Rectangle(hdc,tank->x - 3, tank->y - Tank_Height / 2 - 10,tank->x+3,tank->y - Tank_Height/2);
        break;
    case DOWN:
        Rectangle(hdc, tank->x - 3, tank->y + Tank_Height / 2, tank->x + 3, tank->y + Tank_Height / 2 + 10);
        break;
    case LEFT:
        Rectangle(hdc,tank->x - Tank_Width / 2 - 10,tank->y - 3,tank->x - Tank_Width / 2,tank->y + 3);
        break;
    case RIGHT:
        Rectangle(hdc, tank->x + Tank_Width / 2, tank->y - 3, tank->x + Tank_Width /2 + 10, tank->y + 3);
        break;
    }
    
    SelectObject(hdc, hOldBrush);
}
void CreateBullet(Tank* tank,BulletList* pHend) 
{
    BulletList* pNewNode = new BulletList;
    pNewNode->bullet.direction = tank->direction;
    pNewNode->bullet.x = tank->x;
    pNewNode->bullet.y = tank->y;

    BulletList* p = pHend;
    while (g_hend != NULL&&p->next != NULL)
    {
        p = p->next;
    }
    if (pHend == NULL)
    {
        pHend = pNewNode;
        g_hend = pNewNode;
    }
    else 
    {
        p->next = pNewNode;
    }
}
void DrawBullet(HDC hdc,BulletList* pHend)
{
    BulletList* p = pHend;
    while (p != NULL)
    {
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
        HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, p->bullet.x - 2, p->bullet.y - 2, p->bullet.x + 2, p->bullet.y + 2);
        SelectObject(hdc, hOldBrush);
        p = p->next;
    }
}