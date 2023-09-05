#pragma warning(disable:4996)
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

//程序的入口
int main()
{

	//创建一个画板

	initgraph(800, 600);
	
	//重置坐标原点
	setorigin(400, 300);

	//设置背景
	setbkcolor(WHITE);

	//清空画板
	cleardevice();
	
	setfillcolor(BLUE);
	setlinecolor(BLACK);
	//画圆形
	fillroundrect(-135,-106, 135, -54, 248, 248);
	//circle(100, 100, 50);
	setfillcolor(WHITE);
	fillellipse(-115, -214, 115, -46);

	setfillcolor(BLUE);
	setlinecolor(BLACK);
	//画圆形
	fillroundrect(135,106, -135, 54, 248, 248);
	//circle(100, 100, 50);
	setfillcolor(WHITE);
	fillellipse(-115, 214, 115, 46);
	//防止画板消失
	_getch();
	return 0;
}
