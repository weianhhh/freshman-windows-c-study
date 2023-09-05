#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	initgraph(500, 480);
	int x, y = 50;
	while (1)
	{
		if (y < 460)
			y = y + 1;
		cleardevice();//ÇåÆÁº¯Êý
		fillcircle(240, y, 20);
		Sleep(10);
	}
	return 0;
}