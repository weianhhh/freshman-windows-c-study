#pragma once
#include <list>
#include "cMyTimer.h"
using namespace std;

#define GetFruitTime 10000

enum ObjectType {
	Type_Flower,
	Type_Gun,
	Type_Zomble,
	Type_Bullet,
	Type_Num
};

enum Timer_Type {
	Timer_Draw,
	
};
struct strObjectInfo
{
	int x;
	int y;
	ObjectType type;
	unsigned speed;
	unsigned lastActionTime;
	short cuPicInedx;
	unsigned hpValue;
	unsigned attackValue;
	strObjectInfo()
	{
		x = 0;
		y = 0;
		type = Type_Num;
		lastActionTime = 0;
		hpValue = 100;
		attackValue = 20;
		cuPicInedx = 0;
		speed = 10;
	}
};

typedef list<strObjectInfo> ObjectList;
typedef list<strObjectInfo>::iterator itObjectList;


class cLogic:public cMyTimer {
	public:
		cLogic() {}
		~cLogic() {}
		
		void Begin(HWND hWnd);
		virtual int OnTimer(int id, int iParam, string str);
		
		void Draw();
		void DrawBackPlants(HDC hDc);
		void DrawFlowerAndGun(HDC hDc);
		void DrawBullet(HDC hDc);
		void DrawZombles(HDC hDc);
		void Drawtext(HDC hDc);

private:
	unsigned m_iMoney;
	ObjectList m_listFlower;
	ObjectList m_listGun;
	ObjectList m_listZombies;
	ObjectList m_listBullet;

	HWND m_hWnd;
};
