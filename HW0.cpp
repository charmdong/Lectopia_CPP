#include <windows.h>
#include <stdio.h>
#define BLACK 0
#define GREEN 2
#define YELLOW 14
#define WHITE 15
#define MAX 10

void initEggbox(char *egg);
void boxing();
void animation();
int isBoxFull(char *egg);
void gotoxy(int x, int y);
void textcolor(int, int);
void addEgg(char *);

int main()
{
	boxing();
	return 0;
}

void initEggbox(char *egg)
{
	for (int i = 0; i <MAX ; i++)
		egg[i] = ' ';
	egg[MAX] = '\0';
}

void boxing()
{
	char egg[MAX + 1];
	int weight;

	initEggbox(egg);

	textcolor(YELLOW, BLACK);
	gotoxy(1, 15);
	printf("< %s >\t\t", egg);
	textcolor(GREEN, BLACK);
	printf("Total : 0 개\n");
	gotoxy(0, 0);
	textcolor(WHITE, BLACK);

	while (!isBoxFull(egg)) {
		printf("달걀 무게를 입력해주세요 >> ");
		scanf("%d", &weight);
		if (weight >= 150 && weight <= 500) {
			gotoxy(0, 1);
			printf("+ 적절한 무게의 달걀입니다! +");
			addEgg(egg);
		}
		else if(weight < 150) {
			gotoxy(0, 1);
			printf("+ 너무 가볍습니다! +");
			Sleep(400);
		}
		else {
			gotoxy(0, 1);
			printf("+ 너무 무겁습니다! +");
			Sleep(400);
		}

		gotoxy(0, 0);
		printf("\t\t\t\t\n\t\t\t\t");
		gotoxy(0, 0);
	}
}

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void animation()
{
	int i = 10;
	
	textcolor(YELLOW, BLACK);

	while (i != 15) {
		gotoxy(7, i);
		printf("0");
		Sleep(100);
		printf("\b ");
		i++;
	}
}

void addEgg(char *egg)
{
	animation();

	int i = 0;
	while (egg[i] != ' ')
		i++;
	egg[i] = '0';

	gotoxy(1, 15);
	printf("< %s >\t\t", egg);
	textcolor(GREEN, BLACK);
	printf("Total : %d 개\n", i + 1);
	textcolor(YELLOW, BLACK);

	if (isBoxFull(egg)) {
		gotoxy(2, 14);
		printf(" ++++++++++");
		gotoxy(0, 15);
		printf(">< %s ><\n\n", egg);
		gotoxy(2, 16);
		printf(" ++++++++++\n");
		printf("\n   포장 완료!\n");
	}

	textcolor(WHITE, BLACK);
}

int isBoxFull(char *egg)
{
	if (egg[MAX-1] == '0')
		return 1;
	return 0;
}