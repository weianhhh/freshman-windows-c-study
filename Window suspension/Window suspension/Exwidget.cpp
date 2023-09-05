#include "Exwidget.h"

Exwidget::Exwidget(int w, int h, string imgURL)
{
	this->w = w;
	this->h = h;
	this->color = color;
	this->imgURL = imgURL;
	if (imgURL.size() != 0)
	{
		img = new IMAGE;
		loadimage(img, imgURL.c_str(), this->w, this->h);
	}
	initgraph(this->w, this->h);

}

void Exwidget::SetBkColor(COLORREF color)
{
	this->color = color;
	setbkcolor(color);
	cleardevice();
}

void Exwidget::Show()
{
	/*setfillcolor(this->color);
	cleardevice();*/
	if (imgURL.size() != 0)
		putimage(0, 0, img);

}
