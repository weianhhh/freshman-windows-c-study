#include <stdio.h>
#include <graphics.h>
#include <iostream>
#include "MyStack.h"
//#include <opencv2/opencv.hpp>
IMAGE road, wall,Tank;
#define SPACE 50
#define  ROWS 12
#define COLS 12

struct MyPonit { int x; int y; };

enum direct {p_up,p_down,p_left,p_right};

struct pathNode {
	int dir;
	bool isFind;
};
void initDraw();
void DrawMap(int map[ROWS][COLS]);
void printMap(int map[ROWS][COLS]);
int main()
{
	int map[ROWS][COLS] = {
	1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,1,1,1,1,1,1,1,0,1,1,
	1,0,0,0,1,1,0,0,0,0,1,1,
	1,0,1,0,1,1,0,1,1,0,1,1,
	1,0,1,0,0,1,0,1,1,0,1,1,
	1,0,1,1,1,1,0,1,0,0,1,1,
	1,0,0,0,0,1,0,1,1,1,1,1,
	1,0,1,1,1,1,0,0,0,0,0,1,
	1,0,1,1,1,1,0,1,1,0,1,1,
	1,0,1,1,1,1,0,1,1,0,1,1,
	1,0,1,1,1,1,0,1,1,0,1,1,
	1,1,1,1,1,1,0,1,1,1,1,1
	};
	MyPonit beginPos = { 3,3 };
	MyPonit EndPos = {1,10};
	bool isFindEnd = false;
	pathNode pathMap[ROWS][COLS] = {0};
#if 0
	MyStack<int> stack;
	for (int i = 0; i < 10; i++)
	{
		stack.push(i);
	}
	while (!stack.isEmpty()) {
		printf("%d ", stack.getTop());
		stack.pop();
	}
	printf("\n");
#endif 
	MyStack<MyPonit> stack;
	stack.push(beginPos);
	pathMap[beginPos.y][beginPos.x].isFind = true;
	//寻路
	MyPonit Current = beginPos;
	MyPonit searchPos;

	while (1) {
		searchPos = Current;
		switch (pathMap[Current.y][Current.x].dir)
		{
		case p_up:
			searchPos.y--;
			//改变试探方向
			pathMap[Current.y][Current.x].dir++;
			if (pathMap[searchPos.y][searchPos.x].isFind = 0 &&//没有走过
				map[searchPos.y][searchPos.x] == 0) {//是路，不是障碍！
				//标记走过
				pathMap[searchPos.y][searchPos.x].isFind = 1;
				stack.push(searchPos);
				Current = searchPos;
			}
			break;
		case p_down:
			searchPos.y++;
			//改变试探方向
			pathMap[Current.y][Current.x].dir++;
			if (pathMap[searchPos.y][searchPos.x].isFind = 0 &&//没有走过
				map[searchPos.y][searchPos.x] == 0) {//是路，不是障碍！
				//标记走过
				pathMap[searchPos.y][searchPos.x].isFind = 1;
				stack.push(searchPos);
				Current = searchPos;
			}
			break;
		case p_left:
			searchPos.x--;
			//改变试探方向
			pathMap[Current.y][Current.x].dir++;
			if (pathMap[searchPos.y][searchPos.x].isFind = 0 &&//没有走过
				map[searchPos.y][searchPos.x] == 0) {//是路，不是障碍！
				//标记走过
				pathMap[searchPos.y][searchPos.x].isFind = 1;
				stack.push(searchPos);
				Current = searchPos;
			}
			break;
		case p_right:
			searchPos.x++;
			//改变试探方向
			
			if (pathMap[searchPos.y][searchPos.x].isFind = 0 &&//没有走过
				map[searchPos.y][searchPos.x] == 0) {//是路，不是障碍！
				//标记走过
				pathMap[searchPos.y][searchPos.x].isFind = 1;
				stack.push(searchPos);
				Current = searchPos;
			}
			else {//回退!
				stack.pop();
				Current = stack.getTop();
				
			}
			break;
		}
		if (Current.y == EndPos.y && Current.x == EndPos.x) {
			isFindEnd = true;
			break;
		}
		printf("Current:%d,%d\n",Current.y,Current.x);
		Sleep(1000);
		if (stack.isEmpty()) {
			break;
		}
	}
	if (isFindEnd) {
		printf("找到终点啦!\n");
		while (!stack.isEmpty()) {
			printf("(%d %d)", stack.getTop().y, stack.getTop().x);
			stack.pop();
		}
		printf("\n");
	}

	initDraw();
	DrawMap(map);
	printMap(map);
	printf("\n");
	
	while (1);
	return  0;

}

void printMap(int map[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++) {
			if (map[i][j] == 1) { printf("墙"); }else printf("  ");
		}printf("\n");
	}

}
void initDraw() {
	initgraph(COLS * SPACE, ROWS * SPACE,SHOWCONSOLE);
	//picture load
	loadimage(&road, L"road.bmp", SPACE, SPACE, true);
	loadimage(&wall, L"wall.bmp",SPACE,SPACE,true);
	
}//图形显示
void DrawMap(int map[ROWS][COLS]){
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++) {
			loadimage(&Tank, L"Tank.bmp", SPACE, SPACE, false);

			putimage(i * SPACE, j * SPACE, &Tank);
			if (map[i][j] == 1) { putimage(j * SPACE, i * SPACE, &wall); }
			else printf("  ");
		}printf("\n");
	}
}
/*
int map1[ROWS][COLS] = {

	1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,0,1,1,1,0,0,0,0,0,1,
	1,1,0,1,1,1,0,1,1,1,1,1,
	1,1,0,1,1,1,0,1,1,1,1,1,
	1,1,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,0,1,1,1,0,1,
	1,1,1,1,1,1,0,1,1,1,0,1,
	1,1,1,1,1,1,0,1,1,1,0,1,
	1,1,0,0,0,0,0,1,1,1,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1};
	DrawMap(map1);
	printMap(map1);
*/