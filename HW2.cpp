#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_FILE 20
#define MAX_BUF 1024

void menu();
void realFileName(char *);
void wordPrint(FILE *,char*);
void linePrint(FILE *, char *);

int main()
{
	menu();
	return 0;
}

void menu()
{
	FILE *fp = NULL;
	char realFile[MAX_FILE + 13];
	char menuList[2][15] = { "1.�ܾ� ����","2.�� ����" };
	int choice;

	printf("+----------------------------+\n");
	printf("\t%s\n\t%s\n", menuList, menuList + 1);
	printf("+----------------------------+\n");
	printf("# ���� >> ");
	scanf("%d", &choice);

	switch (choice) {
	case 1: realFileName(realFile); wordPrint(fp, realFile); break;
	case 2: realFileName(realFile); linePrint(fp, realFile); break;
	default: printf("\n+ Wrong Selection +\n");
	}
}

void realFileName(char *realFile)
{
	char fileName[MAX_FILE];

	printf("# ���ϸ��� �Է����ּ��� : ");
	scanf("%s", fileName);
	sprintf(realFile, "%s%s%s", "C:/Data/", fileName, ".txt");		// C����̺꿡 ������ ��ġ�߽��ϴ�.
}

void wordPrint(FILE *fp, char *realFile)
{
	char output[MAX_BUF] = { 0 };
	int cnt = 0;

	fp = fopen(realFile, "rt");
	if (fp == NULL) {
		printf("Cannot open the File\n");
		return;
	}

	printf("\n[[ �� �ܾ ����ϱ� ]]\n");

	while (!feof(fp)) {
		memset(output, 0, strlen(output));
		fscanf(fp, "%s", output);
		if (strlen(output)) {
			printf("%s\n", output);
			cnt++;
		}
	}
	printf("\n�� �ܾ� �� : %d ��\n\n", cnt);
	fclose(fp);
}

void linePrint(FILE *fp, char *realFile)
{
	char output[MAX_BUF];
	int cnt = 0;

	fp = fopen(realFile, "rt");
	if (fp == NULL) {
		printf("Cannot open the File\n");
		return;
	}

	printf("\n[[ ���پ� ����ϱ� ]]\n");

	while (1) {
		if (!fgets(output, sizeof(output), fp)) break;
		output[strlen(output) - 1] = '\0';
		printf("%s\n", output);
		cnt++;
	}
	printf("\n�� �� �� : %d ��\n\n", cnt);
	fclose(fp);
}