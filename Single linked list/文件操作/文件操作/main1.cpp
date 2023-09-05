#pragma warning(disable:4996)
#pragma warning(disable:4700)

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE* fp;
    char filename[10];
    char mode[2];
    char ch = 0;
    printf("请输入文件名:");
    scanf("%s", filename);
    printf("请输入模式:");
    scanf("%1s", mode);
    fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("Cannot open this filename: %s\n", filename);
        exit(0);
    }
    else {
        printf("已成功打开文件%s\n", filename);
    }

    while (ch != '#') {
        ch = getchar();
        fputc(ch, fp);
        putchar(ch);

    }
    putchar(10);
    fclose(fp);
    return 0;
}