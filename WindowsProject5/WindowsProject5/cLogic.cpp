#include "framework.h"
#include "cLogic.h"

void cLogic::Begin(HWND hWnd)
{
	m_hWnd = hWnd;
	m_iMoney = 50;
	strObjectInfo strFlower;
	strFlower.x = 90;
	strFlower.y = 160;
	strFlower.lastActionTime = GetTickCount64();
	strFlower.speed = GetFruitTime;
	strFlower.type = Type_Flower;
	m_listFlower.push_back(strFlower);
	AddTimer(Timer_Draw, 100);
}
int cLogic::OnTimer(int id, int iParam, string str)
{
	switch (id)
	{
	case Timer_Draw:
		Draw();
		break;
	}
	return 1;
}
void cLogic::Draw() 
{
	HDC hDc = GetWindowDC(m_hWnd);
	if (hDc == NULL)
	{
		return;
	}
	HDC dcNem = CreateCompatibleDC(hDc);
	HBITMAP hBitmap = CreateCompatibleBitmap(hDc, 1280, 720);
	SelectObject(dcNem, hBitmap);
	
	BitBlt(hDc, 0, 0, 1280, 720,dcNem,0,0,SRCCOPY);
	ReleaseDC(m_hWnd, hDc);
}

void cLogic::DrawBackPlants(HDC hDc)
{
	HDC dcTemp;
	dcTemp = CreateCompatibleDC(hDc);
	HBITMAP bitmap = (HBITMAP)LoadImage(NULL, _T("./map.bmp"),IMAGE_BITMAP,1280,720,LR_LOADFROMFILE);
	SelectObject(dcTemp,bitmap);
	BitBlt(hDc, 0, 0, 1280, 720, dcTemp, 0, 0, SRCCOPY);
	DeleteObject(dcTemp);
	DeleteObject(bitmap);
}

void cLogic::DrawFlowerAndGun(HDC hDc)
{
}

void cLogic::DrawBullet(HDC hDc)
{
}

void cLogic::DrawZombles(HDC hDc)
{
}

void cLogic::Drawtext(HDC hDc)
{
}
