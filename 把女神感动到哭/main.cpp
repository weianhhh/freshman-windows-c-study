#include <stdio.h>
#include <easyx.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
struct Jet
{
	int x, y;
	int hx, hy;
	unsigned t1,t2,dt;
	IMAGE img;
	bool isshoot;
}jet;

int main()
{
	srand(time(0));
	initgraph(1200,800);

	//mciSendString(L"open 1.mp3",0,0,0);
	//mciSendString(L"play 1.mp3", 0, 0, 0);

	settextcolor(GREEN);
	settextstyle(25,0,L"¿¬Ìå");
	outtextxy(320, 210,L"hello world");
	outtextxy(320, 230, L"hello world");
	outtextxy(320, 250, L"hello world");
	outtextxy(320, 270, L"hello world");
	outtextxy(420, 290, L"----hrh");
	getchar();
	initgraph(1200, 800);
	settextcolor(GREEN);
	settextstyle(25, 0, L"¿¬Ìå");
	outtextxy(320, 210, L"hello c++");
	outtextxy(320, 230, L"hello c++");
	outtextxy(320, 250, L"hello c++");
	outtextxy(320, 270, L"hello c++");
	outtextxy(420, 290, L"----hrh");
	getchar();
	jet.x = rand() % (1200 - 20);
	jet.y = 750;
	jet.hx = jet.x;
	jet.hy = rand() % 400;
	jet.t1 = GetTickCount();
	jet.isshoot = true;
	loadimage(&jet.img,L"ÑÌ»¨µ¯.jpg",20,50);
	putimage(jet.x,jet.y,&jet.img,SRCINVERT);
	while (1);
	return 0;
}
