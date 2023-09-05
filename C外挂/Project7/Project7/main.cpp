#include <graphics.h>
#include <stdio.h>

IMAGE road, wall,grass,home;
#define SPACE 50
#define ROWS 12
#define COLS 12

//void initDraw();
//void DrawMap(int map[ROWS][COLS]);
//void printMap(int map[ROWS][COLS]);

int main() {

	int map[ROWS][COLS] = {
	1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,2,2,2,0,0,2,2,2,1,1,
	1,1,2,2,2,0,0,2,2,2,1,1,
	1,1,0,1,1,0,0,1,1,0,1,1,
	1,1,0,1,1,0,0,1,1,0,1,1,
	1,1,0,0,0,0,0,0,0,0,1,1,
	1,1,0,0,0,0,0,0,0,0,1,1,
	1,1,0,1,1,0,0,1,1,0,1,1,
	1,1,0,1,1,0,0,1,1,0,1,1,
	1,1,2,2,2,0,0,2,2,2,1,1,
	1,1,1,1,1,3,3,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,
	};
	//12*50,12*50 (600,600);
	initgraph(COLS*SPACE,ROWS*SPACE);
	//picture load
	loadimage(&road,L"road.bmp",SPACE,SPACE,true);
	loadimage(&wall, L"wall.bmp", SPACE, SPACE, true);
	loadimage(&grass, L"grass.bmp", SPACE, SPACE, true);
	loadimage(&home, L"home.bmp", SPACE, SPACE, true);
	for (int i = 0; i < ROWS; i++)//y
	{
		for (int j = 0; j < COLS; j++)//x 
		{
			if (map[i][j] == 1) {
				putimage(j * SPACE, i * SPACE, &wall);
			}
			else if (map[i][j] == 2) {
				putimage(j * SPACE, i * SPACE, &grass);
			}
			else if (map[i][j] == 3) {
				putimage(j * SPACE, i * SPACE, &home);
			}
			else {
				printf(" ");
			}
		}
	}
	while (1);
	return 0;
}