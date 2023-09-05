#include <graphics.h>
#include <Windows.h>
int main()
{
	initgraph(400, 800);
	IMAGE mm;
	loadimage(&mm,L"mm.jpg");
	putimage(0, 0, &mm);

	while (1);
	return 0;

}