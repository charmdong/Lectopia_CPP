#include "CircularQueue.h"
#include "Person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

void getInform();	// queue�� text���� ���� �ű�� (�Ѱ����� �Լ�)
int getInformCnt(char *);	// �� ���Ͽ� ������ �ִ� ����� �� ��ȯ
void moveToQue(Queue *, char(*)[20]);
int lottery(Queue *);
void writeToText(FILE *, Person *);
void writeAll(FILE *, Queue *,Person *);
void partLottery(FILE *,Queue *, int);
int random(int);
void printWin();

int main()
{
	srand((unsigned int)time(NULL));
	getInform();
	return 0;
}

void getInform()
{
	char file[3][20] = { "C:/Data/grade1.txt" , "C:/Data/grade2.txt", "C:/Data/grade3.txt"};
	Queue q[3];
	int cnt, i;

	for (i = 0; i < 3; i++) {
		cnt = getInformCnt(file[i]);
		initQueue(&q[i],cnt+1);
	}
	moveToQue(q, file);
	if(lottery(q))
		printWin();
}

int getInformCnt(char *file)
{
	FILE *fp;
	char tmp[MAX];
	int cnt =0;

	fp = fopen(file, "rt");
	if (fp == NULL) {
		printf("\n+ Cannot open File ! +\n");
		return 0;
	}

	while (1) {
		if (!fgets(tmp, sizeof(tmp), fp)) break;
		cnt++;
	}
	fclose(fp);
	return cnt/3;
}

void moveToQue(Queue *ql, char(*file)[20])
{
	FILE *fp;
	Person tmp;
	int i,k=0;

	for (i = 0; i < 3; i++) {
		fp = fopen(file[i], "rt");
		if (fp == NULL) {
			printf("\n + Cannot open File ! +\n");
			return;
		}
		while (fgets(tmp.name, sizeof(tmp.name), fp)!= NULL) {
			tmp.name[strlen(tmp.name) - 1] = '\0';
			fscanf(fp, "%s ", tmp.birth);
			fscanf(fp, "%s ", tmp.phone);

			enqueue(&ql[i], tmp);
		}
		fclose(fp);
	}
	memset(&tmp, 0, sizeof(tmp));
}

int lottery(Queue *ql)
{
	FILE *fp;
	int total = 0, i, lotNum;
	Person tmp;

	for (i = 0; i < 3; i++)
		total += ql[i].cnt;

	printf("# ��÷�� �ο����� �Է����ּ��� : ");
	scanf("%d", &lotNum);

	fp = fopen("C:/Data/win.txt", "w+");
	if (fp == NULL) {
		printf("\n + Cannot open File ! +\n");
		return 0;
	}

	if (lotNum < ql[0].cnt) 	// ��÷ �ο��� 1��� �ο����� ���� ���
		partLottery(fp, &ql[0], lotNum);

	else if (lotNum >= ql[0].cnt && lotNum < ql[0].cnt + ql[1].cnt) {  // ��÷ �ο��� 1��� �ο����� ���� 1+2��� �ο����� ���� ���
		writeAll(fp, &ql[0], &tmp);
		partLottery(fp, &ql[1], lotNum - ql[0].cnt);
	}

	else if (lotNum >= total - ql[2].cnt && lotNum <= total) {  // ��÷ �ο��� 1+2��� �ο����� ���ų� ���� �� �ο����� ���ų� ���� ���
		writeAll(fp, &ql[0], &tmp);
		writeAll(fp, &ql[1], &tmp);
		if (lotNum == total)	// ��÷ �ο� ���� total �ο� ���� ���� ���
			writeAll(fp, &ql[2], &tmp);
		else
			partLottery(fp, &ql[2], lotNum - ql[0].cnt - ql[1].cnt);
	}
	else
		printf("\n+ ��÷�� �ο��� �� �ο����� �����ϴ�. +\n");	
	fclose(fp);
	if (lotNum > total)
		return 0;
	return 1;
}

void partLottery(FILE *fp,Queue *q, int num)
{
	int lot;
	Person tmp;
	
	while (num) {
		lot = random(num--);
		while (--lot) {
			dequeue(q, &tmp);
			enqueue(q, tmp);
		}
		dequeue(q, &tmp);
		writeToText(fp, &tmp);
	}
}

void writeAll(FILE *fp, Queue *q, Person *tmp)
{
	while (!is_empty(q)) {
		dequeue(q, tmp);
		writeToText(fp, tmp);
	}
}

void writeToText(FILE *fp, Person *wp)
{
	fputs(wp->name, fp);
	fputs("\n", fp);
	fputs(wp->birth,  fp);
	fputs("\n", fp);
	fputs(wp->phone, fp);
	fputs("\n", fp);
}

void printWin()
{
	FILE *fp;
	Person tmp;
	int i = 1;
	
	fp = fopen("C:/Data/win.txt", "rt");
	if (fp == NULL) {
		printf("\n + Cannot open FIle ! +\n");
		return;
	}

	printf("[   No.\t��÷�ڸ�\t�ֹι�ȣ\t\t����ó\t\t]\n");
	while (fgets(tmp.name, sizeof(tmp.name), fp)!= NULL) {
		tmp.name[strlen(tmp.name) - 1] = '\0';
		fscanf(fp, "%s ", tmp.birth);
		fscanf(fp, "%s ", tmp.phone);
		if(strlen(tmp.name) >= 8)
			printf("    %d.\t%s\t%s%s\t\t%s\b\b\b\b%s\n", i++,tmp.name, tmp.birth, "-*******", tmp.phone, "****");
		else
			printf("    %d.\t%s\t\t%s%s\t\t%s\b\b\b\b%s\n", i++, tmp.name, tmp.birth, "-*******", tmp.phone, "****");
	}
	memset(&tmp, 0, sizeof(tmp));
	fclose(fp);
}

int random(int num)
{
	int res;
	res = rand() % num;
	return res + 1;
}