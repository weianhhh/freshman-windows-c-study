/* code by W.Z.T */

/* Just For Fun */

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#define SLEEP_TIME1 10
#define SLEEP_TIME2 50
#define SLEEP_TIME3 200
#define SPEED_MOVE1 10
#define SPEED_MOVE2 25
#define SPEED_MOVE3 26
#define SPEED_MOVE4 27

char a[19][13] = {
" ",
" ",
" o ",
" o ",
" o ",
" /@\\ ",
" @@@@@ ",
" ( ) ",
" ( ) ",
" ( ) ",
" ( ) ",
" ( ) ",
" ( )DD ",
" C=(=)==\\",
" C=(=)= |",
" C=(=)= |",
" C=(=)= /",
" @@BBB@@ "
" @@@@@@@ " };

char b[7][13] = {
" /##\\ ",
" @@ ",
" @@ ",
" @@ ",
" @@ ",
" @@@@ ",
" @@BB@@ " };

int sum = 0;
/*

char a[13][13]={
" /#\\ ",
" ##### ",
" I IDD ",
" C=I=I==\\",
" C=I=I= |",
" C=I=I= |",
" C=I=I= /",
" I I ",
" I I ",
" i i ",
" i i ",
" i i ",
" i i ",
" @@BBB@@ "
" @@@@@@@ "};

*/

void Fuck_Microsoft();

int main(void)
{
	int i, j, k, l;

	while (1) {
		sum++;
		if (sum == SPEED_MOVE2) {
			for (i = 2; i > 0; i--) {
				system("cls");
				a[i - 1][6] = a[6];
				a[6] = ' ';
				for (j = 0; j < 19; j++) {
					if (j == 3 || j == 4)
						continue;
					printf("%s\n", a[j]);
				}
				sleep(SLEEP_TIME3);
			}

		}

		if (sum == SPEED_MOVE3) {
			for (i = 3; i > 1; i--) {
				system("cls");
				a[i - 1][6] = a[6];
				a[6] = ' ';
				for (j = 0; j < 19; j++) {
					if (j == 4)
						continue;
					printf("%s\n", a[j]);
				}
				sleep(SLEEP_TIME3 + 100);
			}
		}

		if (sum == SPEED_MOVE4) {
			for (i = 4; i > 2; i--) {
				system("cls");
				a[i - 1][6] = a[6];
				a[6] = ' ';
				for (j = 0; j < 19; j++) {
					printf("%s\n", a[j]);
				}
				sleep(SLEEP_TIME3 + 200);
			}
			break;
		}

		for (i = 12; i > 7; i--) {
			system("cls");
			for (k = i; k <= i + 4; k++) {
				for (l = 3; l < 12; l++) {
					if (l == 5 || l == 7)
						continue;
					a[k - 1][l] = a[k][l];
					a[k][l] = ' ';
				}
			}
			for (j = 5; j < 19; j++) {
				printf("%s\n", a[j]);
			}
			if (sum >= SPEED_MOVE1)
				sleep(SLEEP_TIME1);
			else
				sleep(SLEEP_TIME2);
		}

		for (i = 11; i < 16; i++) {
			system("cls");
			for (k = i; k >= i - 4; k--) {
				for (l = 3; l < 12; l++) {
					if (l == 5 || l == 7)
						continue;
					a[k + 1][l] = a[k][l];
					a[k][l] = ' ';
				}
			}
			for (j = 5; j < 19; j++) {
				printf("%s\n", a[j]);
			}

			if (sum >= SPEED_MOVE1)
				sleep(SLEEP_TIME1);
			else
				sleep(SLEEP_TIME2);
		}
	}

	Fuck_Microsoft();

	return 0;
}

void Fuck_Microsoft()
{
	char* fuck_windows = L"一个程序如果不能看到源代码，就象想用打'手'枪来体验make love的感觉一样蠢\n";
	int i;

	system("cls");

	for (i = 0; i < 8; i++) {
		printf("%s\n", b);
	}

	sleep(SLEEP_TIME3 + 1000);

	for (i = 0; i < strlen(fuck_windows); i++) {
		printf("%c", fuck_windows);
		sleep(SLEEP_TIME2);
	}

	sleep(SLEEP_TIME2 + 1000);
}