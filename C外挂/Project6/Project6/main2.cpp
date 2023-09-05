#include <graphics.h>  
#include <conio.h>

struct Actor
{
	float x;
	float y;
	float vy;
	float g;
	float mass;
	float rebound;
};

void OnUpdate(Actor& actor)
{
	//G = mg
	actor.vy = actor.vy + (actor.mass * actor.g);
	actor.y = actor.y + actor.vy;
	if (actor.y >= 580)
		//在落地时加一个反向的力，实现反弹
		actor.vy = -(0.95 * actor.rebound) * actor.vy;
	if (actor.y > 580)
		actor.y = 580;
	fillcircle(actor.x, actor.y, 20);
}


int main()
{
	//Actor iron;//定义0.9g球1  
	/*iron.x = 150;
	iron.y = 100;
	iron.vy = 0;
	iron.g = 0.9;
	iron.mass = 0.5;
	iron.rebound = 0.3;*/
	Actor iron{ 150,100,0,0.9,1,0.3 };
	Actor ball{ 300,100,0,0.6,1,0.9 };

	initgraph(600, 600);
	while (1)
	{
		cleardevice();
		OnUpdate(iron);
		OnUpdate(ball);
		Sleep(10);
	}
	_getch();
	closegraph();
	return 0;
}