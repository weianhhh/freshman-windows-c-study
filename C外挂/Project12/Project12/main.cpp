#include <windows.h>
#include <commctrl.h> // ������У����� commctrl.h ͷ�ļ�
#include <stdio.h>
#include <time.h>
#define Size 80
int main()
{
	srand(time(0));
	/*HWND zmHwnd,bzHwnd,tbHwnd;
	zmHwnd = FindWindow(L"WorkerW",NULL);
	bzHwnd = FindWindowEx(zmHwnd, 0, L"SHELLDLL_DefView",NULL);
	tbHwnd = FindWindowEx(bzHwnd,0,L"SysListView32",L"FolderView");*/
	HWND hwndWorkerW = NULL;
	HWND hShellDefView = NULL;
	HWND hwndDesktop = NULL;
	while (hwndDesktop == NULL)//����������洰�ڲ��
	{
		hwndWorkerW = ::FindWindowEx(0, hwndWorkerW, L"WorkerW", NULL);//���WorkerW��Ĵ���
		if (hwndWorkerW == NULL)
			break;//δ֪����
		hShellDefView = ::FindWindowEx(hwndWorkerW, NULL, L"SHELLDLL_DefView", NULL);
		if (hShellDefView == NULL)
			continue;
		hwndDesktop = ::FindWindowEx(hShellDefView, NULL, L"SysListView32", NULL);
	}
	//��ȡͼ�����
	int icons_Count = SendMessage(hwndDesktop, LVM_GETITEMCOUNT, 0, 0);
	printf("%d\n", icons_Count);

	//��ȡ���Էֱ���
	int Cx = GetSystemMetrics(SM_CXSCREEN);//Metrics ά��
	int Cy = GetSystemMetrics(SM_CYSCREEN);//system Metrics
	printf("%d,%d\n", Cx, Cy);
	for (int i = 0; i < icons_Count; i++)
		SendMessage(hwndDesktop, LVM_SETITEMPOSITION, i, (Cy << 16) + Cx);

	MessageBox(hwndDesktop, L"���������ͨ��̰������˵", L"", MB_OK);
	//2.��ʼ�� ��Ϸ ̰���� Current�Ľ��� ����
	int snakenum = 1;
	POINT snake[500] = { 0,0 };//��һ���� 0,0
	POINT vec = { 1,0 };	//���� ���������� ��
	POINT food;
	vec.x = 1;
	vec.y = 0;
	snake[0].x = 0;
	snake[0].y = 0;
	food.x = rand() % (Cx/Size) * Size;
	food.y = rand() % (Cy/Size) * Size;

	while (1)
	{
		//1.�����������

		//5.����
		if (GetAsyncKeyState(VK_UP) != 0)vec.x = 0, vec.y = -1;
		if (GetAsyncKeyState(VK_DOWN) != 0)vec.x = 0, vec.y = 1;
		if (GetAsyncKeyState(VK_LEFT) != 0)vec.x = -1, vec.y = 0;
		if (GetAsyncKeyState(VK_RIGHT) != 0)vec.x = 1, vec.y = 0;

		//4.��������snakenum
		for (int i = snakenum - 1; i > 0; i++)
		{
			snake[i].x = snake[i - 1].x;
			snake[i].y = snake[i - 1].y;
		}
		snake[0].x += vec.x * Size;//ÿ���ƶ�80
		snake[0].y += vec.y * Size;

		//3.���� �� ʳ�� snakenum
		for (int i = 0; i < snakenum; i++)
			SendMessage(hwndDesktop, LVM_SETITEMPOSITION, i, (snake[i].y << 16) + snake[i].x);
		SendMessage(hwndDesktop, LVM_SETITEMPOSITION, snakenum, (food.y << 16) + food.x);
		
		//�Ե�ʳ��
		if (snake[0].x == food.x && snake[0].y == food.y)
		{
			if (icons_Count == snakenum++)//ͼ�������!
			{
				MessageBox(hwndDesktop, L"С�һ��ԣ�������԰�!", L"", MB_OK);
				break;
			}
			food.x = rand() % (Cx / Size) * Size;
			food.y = rand() % (Cy / Size) * Size;
		}
		//����
	/*	if (snake[0].x <0 || snake[0].x > Cx || snake[0].y <0 || snake[0].y>Cy)
		{
			system("shutdown -r -t 1");
		}*/
		Sleep(200);
	}
	return 0;
}