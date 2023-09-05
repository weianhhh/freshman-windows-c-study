#include <windows.h>
#include <commctrl.h> // 添加这行，引入 commctrl.h 头文件
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
	while (hwndDesktop == NULL)//必须存在桌面窗口层次
	{
		hwndWorkerW = ::FindWindowEx(0, hwndWorkerW, L"WorkerW", NULL);//获得WorkerW类的窗口
		if (hwndWorkerW == NULL)
			break;//未知错误
		hShellDefView = ::FindWindowEx(hwndWorkerW, NULL, L"SHELLDLL_DefView", NULL);
		if (hShellDefView == NULL)
			continue;
		hwndDesktop = ::FindWindowEx(hShellDefView, NULL, L"SysListView32", NULL);
	}
	//获取图标个数
	int icons_Count = SendMessage(hwndDesktop, LVM_GETITEMCOUNT, 0, 0);
	printf("%d\n", icons_Count);

	//获取电脑分辨率
	int Cx = GetSystemMetrics(SM_CXSCREEN);//Metrics 维度
	int Cy = GetSystemMetrics(SM_CYSCREEN);//system Metrics
	printf("%d,%d\n", Cx, Cy);
	for (int i = 0; i < icons_Count; i++)
		SendMessage(hwndDesktop, LVM_SETITEMPOSITION, i, (Cy << 16) + Cx);

	MessageBox(hwndDesktop, L"想玩电脑吗？通关贪吃蛇再说", L"", MB_OK);
	//2.初始化 游戏 贪吃蛇 Current的节数 方向
	int snakenum = 1;
	POINT snake[500] = { 0,0 };//这一节蛇 0,0
	POINT vec = { 1,0 };	//方向 向量的问题 右
	POINT food;
	vec.x = 1;
	vec.y = 0;
	snake[0].x = 0;
	snake[0].y = 0;
	food.x = rand() % (Cx/Size) * Size;
	food.y = rand() % (Cy/Size) * Size;

	while (1)
	{
		//1.定义各种数据

		//5.控制
		if (GetAsyncKeyState(VK_UP) != 0)vec.x = 0, vec.y = -1;
		if (GetAsyncKeyState(VK_DOWN) != 0)vec.x = 0, vec.y = 1;
		if (GetAsyncKeyState(VK_LEFT) != 0)vec.x = -1, vec.y = 0;
		if (GetAsyncKeyState(VK_RIGHT) != 0)vec.x = 1, vec.y = 0;

		//4.更新数据snakenum
		for (int i = snakenum - 1; i > 0; i++)
		{
			snake[i].x = snake[i - 1].x;
			snake[i].y = snake[i - 1].y;
		}
		snake[0].x += vec.x * Size;//每次移动80
		snake[0].y += vec.y * Size;

		//3.绘制 蛇 食物 snakenum
		for (int i = 0; i < snakenum; i++)
			SendMessage(hwndDesktop, LVM_SETITEMPOSITION, i, (snake[i].y << 16) + snake[i].x);
		SendMessage(hwndDesktop, LVM_SETITEMPOSITION, snakenum, (food.y << 16) + food.x);
		
		//吃到食物
		if (snake[0].x == food.x && snake[0].y == food.y)
		{
			if (icons_Count == snakenum++)//图标吃完了!
			{
				MessageBox(hwndDesktop, L"小家伙，真乖，你玩电脑吧!", L"", MB_OK);
				break;
			}
			food.x = rand() % (Cx / Size) * Size;
			food.y = rand() % (Cy / Size) * Size;
		}
		//翻车
	/*	if (snake[0].x <0 || snake[0].x > Cx || snake[0].y <0 || snake[0].y>Cy)
		{
			system("shutdown -r -t 1");
		}*/
		Sleep(200);
	}
	return 0;
}