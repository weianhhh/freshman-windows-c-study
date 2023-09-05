#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <graphics.h>
#pragma warning(disable:4996)
#define ROW 10
#define COL 10
#define MINE 10
#define SIZE 50
int map[ROW][COL];
int row;
int col;
IMAGE image[12];
void GameInit()
{
	initgraph(ROW * SIZE, COL * SIZE, SHOWCONSOLE);
	srand((unsigned)time(NULL));
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			/*if (i %2 || j %2 == 0)
			{
				map[i][j] = 42;
			}
			else
			{
				map[i][j] = '?';
			}*/
			map[i][j] = 0;
		}
		
	}

	for (int i = 0; i < MINE;)
	{
		int r = rand()%ROW; int c = rand()%COL;
		if (map[r][c] == 0)
		{
			map[r][c] = -1;
			i++;
		}
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == -1)
			{
				for (int m = i - 1; m <= i + 1; m++)
				{
					for (int n = j - 1; n <= j + 1; n++)
					{
						if (map[m][n] != -1 && (m >= 0 && m < ROW && n >= 0 && n < COL))
						{
							map[m][n] ++;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 12; i++)
	{
		char file[20] = "";
		sprintf(file,"./image/%d.jpg",i);

		loadimage(&image[i], file,SIZE,SIZE);
	}
	//加密格子
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j] += 20;
		}
	}
}
void GemeDraw()
{
	
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == -1)
			{
				putimage(j * SIZE, i * SIZE, &image[9]);
			}
			else if (map[i][j] >=0 && map[i][j] <= 8)
			{
				putimage(j * SIZE, i * SIZE,&image[map[i][j]]);
			}
			else if (map[i][j] >= 19 && map[i][j] <= 28)
			{
				putimage(j * SIZE, i * SIZE, &image[10]);
			}
			else if (map[i][j] > 30)
			{
				putimage(j * SIZE, i * SIZE, &image[11]);
			}
		}
	}
}
void openNULL(int row, int col);
int Mouse()
{
	if (MouseHit)
	{
		MOUSEMSG msg = GetMouseMsg();
		row = msg.y / SIZE;
		col = msg.x / SIZE;
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN: 
			if (map[row][col] > 8)
			{
				map[row][col] -= 20;
				openNULL(row, col);
			}
			break;
		case WM_RBUTTONDOWN:
			if (map[row][col] <= 28&&map[row][col] >= 8)
			{
				map[row][col] += 20;
			}
			else {
				map[row][col] -= 20;
			}
			break;
		}
		return map[row][col];
	}
}
void openNULL(int row, int col)
{
	if(map[row][col] == 0)
	{
		for (int i = row - 1; i <=  row + 1; i++)
		{
			for (int j = col - 1; j <= col + 1; j++)
			{
				if (map[i][j] == 20 || map[i][j] != 19 && 
					map[i][j] > 8 &&(i >= 0 && i < ROW &&j >= 0 &&j < COL)) 
				{ 
					map[i][j] -= 20;openNULL(i,j); 
				}
			}
		}
	}
}
void show()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%d  ", map[i][j]);
		}
		putchar(10);
	}
	system("cls");
}
int main()
{
	GameInit();
	while (1)
	{
		//show();
		
		int isok = Mouse();
		GemeDraw();
		if (isok == -1)
		{
			//exit(666);
			int flag = MessageBox(GetHWnd(), "点到雷了,over", "提示", MB_OKCANCEL);
			if (flag == IDOK)
			{
				map[row][col] += 40;
			}
			else
			{
				exit(666);
			}
		}
	}
	getchar();
	return 0;
}