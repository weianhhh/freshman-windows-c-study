#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <dos.h>
int main(void)
{
    int i, strt, ch_out, sector;
    char buf[512];
    printf("insert a diskette into drive A and press any key\n");
    getch();
    sector = 0;
    if (absread(0, 1, sector, &buf) != 0)
    {
        perror("Disk problem");
        exit(1);
    }
    printf("Read Ok\n");
    strt = 3;
    for (i = 0; i < 80; i++)
    {
        ch_out = buf[strt + i];
        putchar(ch_out);
    }
    printf("\n");
    return 0;
}
