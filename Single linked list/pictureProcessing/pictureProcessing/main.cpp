#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <graphics.h>
int map[][11] =
{
	0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,1,1,1,0,0,
	0,0,1,1,1,1,1,1,1,0,0,
	0,0,1,1,0,0,0,1,1,0,0,
	0,0,1,1,0,0,0,1,1,0,0,
	0,0,1,1,0,0,0,1,1,0,0,
	0,0,1,1,1,1,1,1,1,0,0,
	0,0,1,1,1,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0
};

void print()
{
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++)
		{
			if (map[i][j] != 0) {
				//printf("%d ", map[i][j]);
				printf("0");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
int main()
{
	print();
	initgraph(1200, 800);
	/*((COLORREF)(((BYTE)(0) | 
	((WORD)((BYTE)(255)) << 8)) | 
	(((DWORD)(BYTE)(0)) << 16)))*/
	setbkcolor(RGB(94,198,200));
	cleardevice();
	IMAGE image;
	loadimage(&image, L"./image.png");
	putimage(0, 0, &image);
	while (1) {
		Sleep(300);
	};
	return 0;
}
