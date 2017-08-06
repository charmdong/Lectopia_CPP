#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define LEFT 75
#define RIGHT 77
#define ESC 27

void gotoxy(int x, int y);
void game();
void moving(int *xCnt, int check);

int main()
{

	game();
	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void game()
{
	int check = 0;
	char in = 0;
	char ship[4][10] = { "    AA", "   |  |","  <    >","   ++++" };
	int i, y, tmp;
	int xCnt=0, yCnt = 20;

	while (1) {
		if (kbhit()) {
			in = getch();
			
			if (in == -32) {
				in = getch();
				switch (in) {
				case LEFT: check = -1; moving(&xCnt, check); break;
				case RIGHT: check = 1; moving(&xCnt, check); break;
				}
			}
			
			else if (in == ESC) { 
				gotoxy(25, 12);
				break; 
			}
		}

		if (check == -1) {
			y = 21;
			for (i = 0; i < 4; i++) {
				gotoxy(35 + xCnt, y++);
				printf("\t\t");
			}
			xCnt--;
		}
		else if (check == 1)
			xCnt++;

		y = 21;
		for (i = 0; i < 4; i++) {
			gotoxy(35 + xCnt, y++);
			printf("%s", ship[i]);
		}
		if (yCnt == 0) yCnt = 20;
		while (yCnt) {
			if (kbhit()) break;
			if (yCnt == 20) tmp = xCnt;
			gotoxy(40 +tmp, yCnt--);
			printf("@");
			Sleep(20);
			printf("\b ");
		}
		y = 21;
		for (i = 0; i < 4; i++) {
			gotoxy(35 + xCnt, y++);
			printf("\t\t");
		}
	}
}

void moving(int *xCnt, int check)
{
	char ship[4][10] = { "    AA", "   |  |","  <    >","   ++++" };
	int i, y;

	if (*xCnt < -35) *xCnt = -35;
	else if (*xCnt > 35) *xCnt = 35;

	if (check == -1) {
		y = 21;
		for (i = 0; i < 4; i++) {
			gotoxy(35 + *xCnt, y++);
			printf("\t\t");
		}
		(*xCnt)--;
	}

	else if (check == 1)
		(*xCnt)++;

	y = 21;
	for (i = 0; i < 4; i++) {
		gotoxy(35 + *xCnt, y++);
		printf("%s", ship[i]);
	}

	y = 21;
	for (i = 0; i < 4; i++) {
		gotoxy(35 + *xCnt, y++);
		printf("\t\t");
	}
}