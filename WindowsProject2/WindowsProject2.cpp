#include <windows.h>
LRESULT CALLBACK WindowProc(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam) 
{
	switch (message)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		int xpos = LOWORD(lParam);
		int ypos = LOWORD(lParam);
		MessageBox(hWnd,TEXT("aaa"),TEXT("鼠标左键按下"),MB_OK);
		break;
	}
	return DefWindowProc(hWnd,message,wParam,lParam);
};
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadIcon(NULL, IDI_ERROR);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = TEXT("WIN");
	wc.lpszMenuName = NULL;
	wc.style = 0;
	RegisterClass(&wc);
	HWND hwnd = CreateWindow(
		wc.lpszClassName,
		TEXT("windows"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,NULL,
		hInstance,NULL);
	ShowWindow(hwnd,SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	MSG msg;
	while (1)
	{
		if (GetMessage(&msg, NULL, 0, 0) == FALSE) {
			break;
		}

		DispatchMessage(&msg);
	}
	
	return 0;
}