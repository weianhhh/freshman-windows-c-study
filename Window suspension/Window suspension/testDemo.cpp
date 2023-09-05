//#include <stdio.h>
//#include <graphics.h>
#include "Exwidget.h"
#include "button_test.h"
/*typedef int int_array[4];
typedef struct Node
{
	int data;
	struct Node* next;
}NODE, * LPNODE.ARRAY[4];*/
// Ö÷º¯Êý
int main()
{
	mciSendString("open D:\\1.mp3", 0, 0, 0);
	/*int_array array;
	int_array array;
	struct Node* x;
	NODE x;
	struct Node* p;
	LPNODE p;
	printf("%d\n",&array);*/
/*	initgraph(800, 600);
	IMAGE background;
	loadimage(&background, _T("D:\\test.jpg",800,600));
	printf("%d\n",&array);*/
/*putimage(0, 0, &background);*/
	Exwidget w(1000, 800,"D:\\test.jpg");
	//w.SetBkColor(RED);
	//w.Show();
	Button* play = new Button(0, 0, 100, 25, LIGHTGRAY, "play");
	Button* pause = new Button(0, 30, 100, 25, LIGHTGRAY, "pause");
	Button* close = new Button(0, 60, 100, 25, LIGHTGRAY, "close");
	
	ExMessage msg;
	BeginBatchDraw();
	while (1)
	{
		w.Show();
		play->Show();
		close->Show();
		pause->Show();
		FlushBatchDraw();
		while (peekmessage(&msg))
		{
			if (play->MouseEvent(msg))
			{
				mciSendString("play D:\\1.mp3 repeat", 0, 0, 0);
			}
			if (pause->MouseEvent(msg))
			{
				/*mciSendString("pause D:\\1.mp3", 0, 0, 0);*/
				if (pause->GetText() == "pause")
				{
					pause->SetText("resume");
					mciSendString("resume D:\\1.mp3", 0, 0, 0);
				}
				else
				{
					pause->SetText("pause");
					mciSendString("pause D:\\1.mp3", 0, 0, 0);
				}
			}

			if (close->MouseEvent(msg))
			{
				mciSendString("close D:\\1.mp3", 0, 0, 0);
			}
		}
	}
	EndBatchDraw();
	/*rectangle(500, 450, 455, 455);
	circle(200, 200,100);
	ExMessage msg;
	msg.x;
	msg.y;
	while (1) 
	{
		peekmessage(&msg);
		if (msg.message == WM_LBUTTONDOWN)
		{
			setfillcolor(LIGHTGREEN);
			fillcircle(msg.x, msg.y, 50);
		}
		if (msg.message == WM_RBUTTONDOWN)
		{
			setfillcolor(RED);
			fillrectangle(msg.x - 25, msg.y - 25, msg.x + 25, msg.y + 25);
		}
	}
	//closegraph();*/
	return 0;
}
