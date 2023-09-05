#pragma once
#include "common.h"
class Button
{
public:
	Button(int x, int y, int w, int h, COLORREF curColor, string text = "");
	void Show();
	bool MouseEvent(ExMessage msg);
	void SetText(string text);
	string GetText();

protected:
	int x;
	int y;
	int w;
	int h;
	COLORREF curColor;
	COLORREF oldColor;
	string text;

};