#pragma warning(disable:4996)
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

//��������
int main()
{

	//����һ������

	initgraph(800, 600);
	
	//��������ԭ��
	setorigin(400, 300);

	//���ñ���
	setbkcolor(WHITE);

	//��ջ���
	cleardevice();
	
	setfillcolor(BLUE);
	setlinecolor(BLACK);
	//��Բ��
	fillroundrect(-135,-106, 135, -54, 248, 248);
	//circle(100, 100, 50);
	setfillcolor(WHITE);
	fillellipse(-115, -214, 115, -46);

	setfillcolor(BLUE);
	setlinecolor(BLACK);
	//��Բ��
	fillroundrect(135,106, -135, 54, 248, 248);
	//circle(100, 100, 50);
	setfillcolor(WHITE);
	fillellipse(-115, 214, 115, 46);
	//��ֹ������ʧ
	_getch();
	return 0;
}
