#ifndef _TOOLS_H_
#define _TOOLS_H_
#include<graphics.h>
typedef unsigned long COLORREF;
typedef unsigned char byte;
typedef struct ARGB
{
	byte a;
	byte r;
	byte g;
	byte b;
}ARGB;

/// <summary>
/// �ֽ�RGB�ϳɵ���ɫ
/// </summary>
/// <param name="c">���ֽ����ɫ</param>
ARGB DecompositionColor(COLORREF c)
{
	byte r = (byte)c;
	byte g = (byte)(c >> 8);
	byte b = (byte)(c >> 16);
	byte a = (byte)(c >> 24);
	ARGB res = { a,r,g,b };
	return res;
}
/// <summary>
/// ����PNG͸��ͼƬ
/// </summary>
/// <param name="x">ͼƬ���ϽǺ�����</param>
/// <param name="y">ͼƬ���Ͻ�������</param>
/// <param name="img">Ҫ���Ƶ�ͼƬָ��</param>
void showimage(int x, int y, IMAGE* img)
{
	DWORD* pdraw = GetImageBuffer();
	DWORD* pImg = GetImageBuffer(img);
	int win_w = getwidth();
	int win_h = getheight();
	int img_w = img->getwidth();
	int img_h = img->getheight();
	int imgx = 0;
	for (int i = 0; i < img->getwidth(); i++)
	{
		for (int k = 0; k < img->getheight(); k++)
		{
			int index = k * img_w + i;//��ǰIMG����λ��
			ARGB img_argb = DecompositionColor(pImg[index]);
			imgx = (y + k) * win_w + (i + x);

			if (img_argb.a != 0 && imgx >= 0 && imgx < win_w * win_h)
			{
				pdraw[imgx] = pImg[index];
			}
		}
	}
}
#endif // !_TOOLS_H_
