#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define ESC 27

void gotoxy(int x, int y);
void game();
void shooting(int *cnt,int check);

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
	int cnt=0, check = 0;
	char in;
	
	while (1) {
		if (kbhit()) {
			in = getch();
			
			if (in == -32) {
				in = getch();

				if (in == 75)
					check = -1;
				else if (in == 77)
					check = 1;
			}

			else if (in == ESC) { 
				gotoxy(25, 12);
				break; 
			}
		}
		
		if (cnt < -35) cnt = -35;
		else if (cnt > 35) cnt = 35;
		
		shooting(&cnt, check);	
		check = 0;
	}
}

void shooting(int *cnt, int check)
{
	char ship[4][10] = { "    AA", "   |  |","  <    >","   ++++" };
	int i,y;

	if (check == -1) {
		y = 21;
		for (i = 0; i < 4; i++) {
			gotoxy(35 + *cnt, y++);
			printf("\t\t");
		}
		(*cnt)--;
	}

	else if (check == 1)
		(*cnt)++;

	y = 21;
	for (i = 0; i < 4; i++) {
		gotoxy(35 + *cnt, y++);
		printf("%s", ship[i]);
	}

	y = 20;
	while (y) {
		gotoxy(40+*cnt, y--);
		printf("@");
		Sleep(20);
		printf("\b ");
	}

	y = 21;
	for (i = 0; i < 4; i++) {
		gotoxy(35 + *cnt, y++);
		printf("\t\t");
	}
}