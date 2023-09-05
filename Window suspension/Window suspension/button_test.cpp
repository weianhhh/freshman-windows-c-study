#include "button_test.h"

Button::Button(int x, int y, int w, int h, COLORREF curColor, string text)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->curColor = curColor;
	this->text = text;
}

void Button::Show()
{
	setfillcolor(curColor);
	setlinecolor(BLACK);
	fillrectangle(x, y, x + w, y + h);

	settextstyle(15, 0, "simkai.ttf");
	int textw = textwidth(text.c_str());
	int texth = textheight(text.c_str());
	int xx = x + (w - textw) / 2;
	int yy = y + (h - texth) / 2;
	setbkmode(TRANSPARENT);
	outtextxy(xx, yy, text.c_str());
}

bool Button::MouseEvent(ExMessage msg)
{
	bool inButton = false;
	if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
	{
		curColor = LIGHTBLUE;
		inButton = true;
	}
	else
	{
		curColor = oldColor;
	}
	if (inButton == true && msg.message == WM_LBUTTONDOWN)
	{
		return true;
	}
	return false;
}

void Button::SetText(string text)
{
	this->text = text;
}

string Button::GetText()
{
	return text;
}


