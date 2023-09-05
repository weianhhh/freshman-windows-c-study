#include <stdio.h>
#include <easyx.h>
#pragma warning(disable:4996)
#define ROW 6
#define COL 4
#define IMG_SIZE 128
IMAGE img[2];
IMAGE img_car[4];
void loadImg()
{
	
	loadimage(img + 0, "./images/background.png");
	loadimage(img + 1, "./images/track.png");
	for (int i = 0; i < 4; i++)
	{
		char file[20] = "";
		sprintf(file, "./images/00%d.png", i);
		loadimage(&img_car[i], file);
	}
}
void draw()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (j == 1 || j == 2)
			{
				putimage(j * IMG_SIZE, i * IMG_SIZE, img+1);
			}
			else
			{
				putimage(j * IMG_SIZE, i * IMG_SIZE, img);
			}
		}
	}
	//美化车道
	setlinestyle(PS_SOLID, 3);//实线
	setlinecolor(BLACK);
	line(IMG_SIZE, 0, IMG_SIZE, IMG_SIZE * ROW);
	line(IMG_SIZE*3, 0, IMG_SIZE*3, IMG_SIZE * ROW);
	
	setlinecolor(WHITE);
	line(IMG_SIZE * 2, 0, IMG_SIZE * 2, IMG_SIZE * ROW); 

	/*setlinestyle(PS_DASHDOTDOT, 3);
	setlinecolor(WHITE);
	line((IMG_SIZE * 2)-64, 0, (IMG_SIZE * 2)-64, IMG_SIZE * ROW);
	line((IMG_SIZE * 2) + 64, 0, (IMG_SIZE * 2) + 64, IMG_SIZE * ROW);*/

}
struct Line
#define Line_Num 30
{
	int x;
	int y;
	int len;
}lines[30];

void initLines()
{
	for (int i = 0; i < Line_Num; i++)
	{
		lines[i].len = 50;
		if (i < Line_Num / 2)
		{
			lines[i].x = IMG_SIZE + IMG_SIZE / 2;
			lines[i].y = i * (25 + lines[i].len);
		}
		else
		{
			lines[i].x = IMG_SIZE *2 + IMG_SIZE / 2;
			lines[i].y = (i - Line_Num / 2) * (25 + lines[i].len)+25;
		}
	}
}
void drawLines()
{
	for (int i = 0; i < Line_Num; i++)
	{
		line(lines[i].x, lines[i].y, lines[i].x, lines[i].y + lines[i].len);
	}
}
void moveLines()
{
	for (int i = 0; i < Line_Num; i++)
	{
		lines[i].y += 2;
		if (lines[i].y > getheight())
		{
			lines[i].y = -lines[i].len;
		}
	}
}
struct Car
{
	int x;
	int y;
	int speed;
	int i;
};
struct Car Player;
int carX[4] =
{
	IMG_SIZE + 10,
	IMG_SIZE / 2 * 3 + 10,
	IMG_SIZE * 2 + 10,
	IMG_SIZE / 2 * 5 + 10,
};
void initCar()
{
	Player.x = carX[rand() % 4];
	Player.y = getheight() - 10;
	Player.speed = 1;
	Player.i = 3;
}
void drawCar()
{
	putimage(Player.x, Player.y, img_car + Player.i);
}

int main()
{
	initgraph(COL * IMG_SIZE, ROW * IMG_SIZE);
	loadImg();
	initLines();
	BeginBatchDraw();
	while(true)
	{	
		draw();
		drawLines();
		//moveLines();
		drawCar();
		FlushBatchDraw();
	}
	EndBatchDraw();
	while (1);
	return 0;
}