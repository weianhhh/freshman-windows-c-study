#include <Windows.h>
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK Mouseproc(int nCode, WPARAM wParam, LPARAM lParam);
HHOOK g_hMouseHook;
int WINAPI WINMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//���һ������
	TCHAR szAPPClssName[] = TEXT("Dunkaidu");
	WNDCLASS wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = szAPPClssName;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	//ע�ᴰ����
	RegisterClass(&wc);
	//��������
	HWND hWnd = CreateWindow(szAPPClssName, TEXT("��������޹�˾"), WS_OVERLAPPEDWINDOW, 400, 100, 800, 600, NULL, NULL, hInstance, NULL);
	//��ʾ����
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg)
	{
	case MH_CREATE:
		g_hMouseHook = SetWindowsHookEx(WH_MOUSE, Mouseproc, NULL, GetCurrentThreadId());
		break;
	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		TCHAR str[255];
		wsprintf(str, L"��ǰ������꣨%d,%d��", x, y);
		SetWindowText(hWnd, str);
	}
	case WM_LBUTTONDOWN:
		MessageBox(hWnd, L"��갴��", L"��ʾ", MB_OK);
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//WH_QUIT
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
LRESULT CALLBACK Mouseproc(int nCode, WPARAM wParam, LPARAM lParam) {

	return CallNextHookEx(g_hMouseHook, nCode, wParam, lParam);
}