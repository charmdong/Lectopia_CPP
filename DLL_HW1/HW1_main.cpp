#include "pattern.h"
#include "doublyLinkedlist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_FILE 20
#define MAX_BUF 100

void getFileName(char *,char *);
void totalPattern(char *);
void analyPattern(char *, int num, List *lp);
void printPattern(char *pattern, List *lp);
void sortPattern(List *lp);

int main()
{
	char file[MAX_FILE];
	char real[MAX_FILE + 13] = { 0 };
	
	printf("# ���ϸ��� �Է����ּ��� : ");
	scanf("%s", file);

	getFileName(real, file);
	totalPattern(real);
	return 0;
}

void getFileName(char *real, char *file)
{
	sprintf(real, "%s%s%s", "C:/Data/", file, ".txt");
}

void totalPattern(char *real)
{
	FILE *fp;
	List lp;
	char pattern[MAX_BUF];
	int num;

	fp = fopen(real, "rt");
	if (fp == NULL) {
		printf("Cannot open File!\n");
		return;
	}

	printf("* �˻��� ������ ���̸� �Է��Ͻÿ� : ");
	scanf("%d", &num);
	printf("\n");
	while (1) {
		if (!fgets(pattern,sizeof(pattern), fp)) break;
		pattern[strlen(pattern) - 1] = '\0';
		createList(&lp);
		analyPattern(pattern, num, &lp);
		printPattern(pattern, &lp);
		destroyList(&lp, patternClear);
	}
	fclose(fp);
}

void analyPattern(char *pattern, int num,List *lp)
{
	Pattern pt = { 0 };
	Node *same;
	int i,j;
	char tmp[MAX_LEN] = { 0 };	// �ӽ� ���� �����

	for (i = 0; i <= strlen(pattern) - num; i++) {
		for (j = 0; j < num; j++)
			tmp[j] = pattern[i + j];
		strcpy(pt.pattern, tmp);
		
		same = searchNode(lp, &pt, patternCompare);
		if (same == NULL) {			// ���ο� ������ ���
			pt.cnt = 1;
			addLast(lp, &pt, sizeof(Pattern), patternCpy);
		}
		else    // ������ �����ϴ� ������ ���
			changeData(lp, &pt, patternCompare, patternDataChange);
	}
}

void printPattern(char *pattern, List *lp)
{
	Node *cur;

	sortPattern(lp);
	printf("** ��Ʈ�� : [ %s ]�� �˻� ��� **\n", pattern);
	displayList(lp, patternPrint);
	printf("------------------------------------------------------------------------------------\n");
}

void sortPattern(List *lp)
{
	sortList(lp, sizeof(Pattern), patternCompare, patternCpy);
}