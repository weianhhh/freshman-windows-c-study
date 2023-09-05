#include <stdio.h>
#include <easyx.h>
#include <math.h>
#include <time.h>
#define width 900
#define height 600

typedef struct _Pos 
{
	double x, y;
	struct _Pos() :x(0), y(0) {};
	struct _Pos(double _x,double _y) :x(_x), y(_y) {};
	bool operator == (struct _Pos _pos)
	{
		if (x == _pos.x && y == _pos.y)
		{
			return true;
		}
		return false;
	}
	void operator += (struct _Pos _pos)
	{
		x += _pos.x;
		y += _pos.y;
	}
	
}Pos;
IMAGE img;

void init();

void  draw();

void update();

Pos Lerp(Pos _lastPos,Pos _targetPos,float Alpha)
{
	return Pos((_targetPos.x - _lastPos.x) * Alpha, (_targetPos.y - _lastPos.y) * Alpha);
}

Pos lastPos;
Pos currentPos;
Pos targetPos;
Pos lerp;

int Width = 0;
int Height = 0;

int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));
	Width = GetSystemMetrics(SM_CXFULLSCREEN);
	Height = GetSystemMetrics(SM_CYFULLSCREEN);
	HWND hwnd = initgraph(width,height,EW_SHOWCONSOLE);
	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd,RGB(0,0,0),0,LWA_COLORKEY);
	SetWindowPos(hwnd,HWND_TOPMOST,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE);
	init();
	while (true)
	{
		draw();
		update();
		Sleep(1);
	}
	return 0;
}
void init() 
{
	loadimage(&img, L"miao.png");
}
void draw()
{
	cleardevice();
	putimage(currentPos.x, currentPos.y, &img);
}
void update()
{

	if (currentPos == targetPos)
	{
		lastPos = targetPos;
		targetPos = Pos(rand()% (width-320), rand() % (height-180));
		lerp=Lerp(lastPos,targetPos,0.010f);
	}
	else if(sqrt((targetPos.x - currentPos.x) * (targetPos.x - currentPos.x) + (targetPos.y - currentPos.y) *
		(targetPos.y - currentPos.y)) <= 2)
	{
		currentPos = targetPos;
	}
	else 
	{
		currentPos += lerp;
	}
	/*currentPos.x = 500;
	currentPos.y = 300;*/
}