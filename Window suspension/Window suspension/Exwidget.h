#pragma once
#include "common.h"
class Exwidget
{
public:
	Exwidget(int w=WIDTH, int h=HEIGHT,string imgURL = "");
	void SetBkColor(COLORREF color);
	void Show();
protected:
	int w;
	int h;
	COLORREF color;//µÈÐ§unsigned long
	/*IMAGE* img;
	const char* imgURL;*/
	string imgURL;
	IMAGE* img;

};