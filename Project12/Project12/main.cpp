#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define IMAGE_WIDTH 77
#define IMAGE_HEIGHT 149
struct srcPos {
	int x;
	int y;

}currentPos;
int main() {


	initgraph(WINDOW_WIDTH,WINDOW_HEIGHT,1);
	IMAGE map, plants1, plants2, bullet, zombie;

	loadimage(&map, L"map.bmp");
	loadimage(&plants1, L"plants1.bmp");
	loadimage(&plants2, L"plants2.bmp");
	loadimage(&bullet, L"bullet.bmp");
	loadimage(&zombie, L"zombie.bmp");
 

	putimage(0,0,&map);
	putimage(100, 160, &plants1);
	putimage(200,160,&plants2);
#
	struct srcPos currentPos;
	currentPos.x = 600;
	currentPos.y = 120;

	// 使用嵌套循环绘制多张素材图片
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			putimage(currentPos.x, currentPos.y, IMAGE_WIDTH, IMAGE_HEIGHT, &zombie, j * IMAGE_WIDTH, i * IMAGE_HEIGHT,SRCPAINT); // 注意这里的参数
			printf("%d %d ", j * IMAGE_WIDTH, i * IMAGE_HEIGHT);
			currentPos.x += IMAGE_WIDTH; // 在同一行上绘制连续的素材动作
		}
		printf("\n");

		// 恢复 x 坐标，更新 y 坐标以开始新行
		currentPos.x = 600;
		currentPos.y += IMAGE_HEIGHT;
	}

	//putimage(600, 120, 77, 149, &zombie,0,0);
	//putimage(700, 120, 77, 149, &zombie,77, 0);
	//putimage(800, 120, 77, 149, &zombie,77 * 2 ,0);
	//putimage(900, 120, 77, 149, &zombie, 77 * 3, 0);

	//putimage(600, 280, 77, 149, &zombie, 0, 149);
	//putimage(700, 280, 77, 149, &zombie, 77  , 149 );
	//putimage(800, 280, 77, 149, &zombie, 77 * 2 , 149 );
	//putimage(900, 280, 77, 149, &zombie, 77 * 3, 149);


	//putimage(600,440, 77, 149, &zombie, 0, 149*2);
	//putimage(700, 440, 77, 149, &zombie, 77*2, 149*2);
	//putimage(800, 440, 77, 149, &zombie, 77 * 2, 149*2);
	//putimage(900, 440, 77, 149, &zombie, 77 * 3, 149*2);

	//putimage(100, 440, 77, 149, &zombie, 0, 149 * 3);
	//putimage(200, 440, 77, 149, &zombie, 77 , 149 * 3);
	//

	while (1);


	return 0;
	
}  
