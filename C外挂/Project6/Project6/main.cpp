#include<graphics.h>
#include<conio.h>
#define High 240
#define Width 320

int main()
{
	float ball_x, ball_y;
	float ball_vx, ball_vy;
	float r;

	initgraph(Width, High);
	ball_x = Width / 4; //80
	ball_y = High / 4; // 60
	ball_vx = 1;
	ball_vy = 1;
	r = 20;

	BeginBatchDraw();
	while (1)
	{
		setcolor(RGB(0,0,255));//运行轨迹外围
		setfillcolor(RGB(0,255,0));//运行轨迹
		fillcircle(ball_x, ball_y, r);//用绘图函数画圆(ball_x, ball_y）是坐标，r为半径
		ball_x = ball_x + ball_vx; //80 + 1
		ball_y = ball_y + ball_vy; // 60 + 1 

		if ((ball_x <= r) || (ball_x >= Width - r)) // 81 <= 20 || 681 >= 320 -20
			ball_vx = -ball_vx;// start:ball_vx =- (vx=1)
		if ((ball_y <= r) || (ball_y >= High - r)) // 61 <= 20 || 61 >= 240 -20
			ball_vy = -ball_vy;//start:ball_vx =- (vy=1)

		setcolor(RGB(255,0,0));//圆的边边的线
		setfillcolor(RGB(255,255,255));//圆的内部实体
		fillcircle(ball_x, ball_y, r);//画出这个圆

		FlushBatchDraw();

		Sleep(1);
	}
	EndBatchDraw();
	closegraph();
	return 0;
}