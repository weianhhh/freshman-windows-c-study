#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
int main() {
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    int t = 1;
    while (t++) {
        COORD huoquan;
        COORD xiangling = { 40,15 };
        int R = 13;
        huoquan.X = xiangling.X + 2 * R * cos(t * 0.2);
        huoquan.Y = xiangling.Y + R * sin(t * 0.2);
        system("cls");
        SetConsoleCursorPosition(hOutput, xiangling);
        printf("香菱");
        SetConsoleCursorPosition(hOutput, huoquan);
        printf("火圈");
        CONSOLE_CURSOR_INFO curInfo = {1,FALSE};
        SetConsoleCursorInfo(hOutput,&curInfo);
    }

}