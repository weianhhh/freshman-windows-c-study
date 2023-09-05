#include <easyx.h>
#include <stdio.h>
#include <math.h>
#define GRID_W 25
#define INTERVAL (3*GRID_W)
#define ROW 15
#define COL 15
int map[ROW][COL];
bool judge(int r, int c);
enum Chess {None,Black,White};
struct {
	int x;
	int y;
	bool isSHow;
	int row;
	int col;
	Chess chessPlayer;
}op;
void draw()
{
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	for (int i = 0; i < 15; i++) {
		line(INTERVAL,INTERVAL+i*GRID_W,GRID_W*14+INTERVAL,INTERVAL+i*GRID_W);
		line(INTERVAL + i * GRID_W,INTERVAL ,INTERVAL + i * GRID_W,INTERVAL + GRID_W * 14);
	}
	setlinestyle(PS_SOLID, 2);
	rectangle(INTERVAL, INTERVAL, INTERVAL + GRID_W * 14, INTERVAL + GRID_W *14);
	setfillcolor(BLACK);
	solidcircle(2 * GRID_W + INTERVAL, 7 * GRID_W + INTERVAL, 5);	
	solidcircle(3 * GRID_W + INTERVAL, 7 * GRID_W + INTERVAL, 5);
	solidcircle(4 * GRID_W + INTERVAL, 7 * GRID_W + INTERVAL, 5);
	solidcircle(5 * GRID_W + INTERVAL, 7 * GRID_W + INTERVAL, 5);
	solidcircle(6 * GRID_W + INTERVAL, 7 * GRID_W + INTERVAL, 5);
	setfillcolor(WHITE);
	solidcircle((7-4) * GRID_W + INTERVAL, (7+4) * GRID_W + INTERVAL, 5);
	solidcircle(7 * GRID_W + INTERVAL, 8 * GRID_W + INTERVAL, 5);
	solidcircle((7+4) * GRID_W + INTERVAL, (7-4) * GRID_W + INTERVAL, 5);
	if (op.isSHow)
	{
		setlinecolor(BLUE);
		rectangle(op.x - 12, op.y - 12, op.x + 12, op.y + 12);
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++)
		{
			switch (map[i][j]) {
			case None:
				break;
			case Black:
				setfillcolor(BLACK);
				solidcircle(j * GRID_W + INTERVAL, i * GRID_W + INTERVAL,10);
				break;
			case White:
				setfillcolor(WHITE);
				solidcircle(j * GRID_W + INTERVAL, i * GRID_W + INTERVAL,10);
				break;
			default:
				break;
			}
		}
	}
}

void mouseEvnet() {
	ExMessage msg;
	if (peekmessage(&msg, EX_MOUSE))
	{
		op.isSHow = false;
		for (int i = 0; i < 15; i++)
		{
			for (int k = 0; k < 15; k++)
			{
				int gridx = (k + 3) * GRID_W;
				int gridy = (i + 3) * GRID_W;
				if (abs(msg.x - gridx) < 12 && abs(msg.y - gridy) < 12) {
					op.x = gridx;
					op.y = gridy;
					op.isSHow = true;
					op.row = i;
					op.col = k;
				}

			}
		}
		if (msg.message == WM_LBUTTONDOWN && map[op.row][op.col] == None)
		{
			map[op.row][op.col] = op.chessPlayer;
			if (judge(op.row, op.col))
			{
				MessageBox(GetHWnd(), "Ê®Èýµã", op.chessPlayer == White?"White":"Black", MB_OK);
			}
			op.chessPlayer = (op.chessPlayer == Black ? White : Black);
		}

	}
}

bool judge(int r,int c)
{
	for (int i = c -4; i <= c; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 5;j++)
		{
			if (i>=0&&i<=COL -4 && op.chessPlayer == map[r][i + j]) {
				cnt++;
			}
		}
		if (cnt == 5)
		{
			return true;
		}
		else {
			return false;
		}
	}
}
int main()
{
	initgraph(600,500);
	
	IMAGE img;
	loadimage(&img, "./qipan.jpg");
	int width = img.getheight();
	int height = img.getwidth();
	printf("%d%d\n",width,height);
	putimage(0,0,&img);
	while (true)
	{
		cleardevice();
		putimage(0, 0, &img);
		draw();
		mouseEvnet();
		FlushBatchDraw();
	}
	EndBatchDraw();
	return 0;
}