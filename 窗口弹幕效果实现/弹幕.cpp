#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int main()
{
	initgraph(500, 600);
	clearcircle(320, 240, 0);
	_getch();
	rectangle(200,400,200,400);
	closegraph();
	while (1);
	
	return 0;
}