#include <windows.h>
HINSTANCE g_hinstance;
LRESULT CALLBACK WndProc(HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	switch (nMsg) 
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	}
	return DefWindowProc(hwnd, nMsg, wParam, lParam);
}
BOOL MyRegister(LPSTR pszClassName) 
{
	ATOM nAtom;
	WNDCLASS wc = { 0 };
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = g_hinstance;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = pszClassName;
	nAtom = RegisterClass(&wc);
	if (0 == nAtom) 
	{
		MessageBox(NULL,L"Register Failed", L"Error", MB_OK | MB_ICONWARNING);
		return FALSE;
	}
	else
	{
		MessageBox(NULL, L"register Successed", L"Successed", MB_OK);
	}
	return TRUE;
}
HWND MyCreate(LPSTR pszClassName)
{
	HWND hwnd = CreateWindowA(pszClassName, "helloWnd!", WS_OVERLAPPEDWINDOW,100,100,300,500,NULL,NULL,g_hinstance,NULL);
	if (NULL == hwnd) 
	{
		MessageBox(NULL, L"Create window Failed", L"Error", MB_OK | MB_ICONWARNING);
		return NULL;
	}
	else 
	{
		MessageBox(NULL,L"Create Window Successed",L"Successed", MB_OK);
	}
	return hwnd;
}
void DispalyWnd(HWND hwnd) 
{
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
}

void Message()
{
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessageW(&msg);
	}
}

int main(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR pszCmdLine, int nCmdSHhow)
{
	HWND hwnd = NULL;
	BOOL bret = FALSE;
	bret = MyRegister(L"HWND");
	if (FALSE == bret)
	{
		MessageBox(NULL, L"Register window Failed", L"Error", MB_OK | MB_ICONWARNING);
		return -1;
	}

	else
	{
		MessageBox(NULL, L"Register window Successed", L"Successed", MB_OK | MB_ICONWARNING);
	}
	g_hinstance = hinstance;
	hwnd = MyCreate(L"HWND");
	if (NULL == hwnd)
	{
		MessageBox(NULL, L"Createwindow Failed", L"Failed", MB_OK);
	}
	DispalyWnd(hwnd);
	Message();
	return 0;
}
