#include "circularQueue.h" 
#include "person.h"
#include <stdio.h> 
int menu(const char **, int);
void myFlush();
void input(Queue *);
void myDelete(Queue *);
/*--------------------------------------------------------------------------------
   Function name	:  main() 
---------------------------------------------------------------------------------*/
int main()
{
	Queue que;		/* 큐 관리구조체 선언*/
	const char *menuList[] = { "입력하기", "삭제하기", "출력하기", "종료" }; /* 메뉴리스트*/
	int menuCnt;	/* 메뉴개수 저장 변수*/
	int menuNum;	/* 메뉴번호 저장 변수*/

	createQueue(&que, 5, sizeof(Person)); /* 크기가 5인 큐 생성 및 초기화*/

	menuCnt = sizeof(menuList) / sizeof(menuList[0]); /* 메뉴 개수 계산 하기*/
	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt) /* 종료메뉴 선택 시 반복문 탈출 하기*/
		{
			break;
		}
		switch (menuNum)
		{
		case 1: input(&que); break;
		case 2: myDelete(&que); break;
		case 3: printQueue(&que, sizeof(Person), personPrint); /* queue내의 모든 데이터 출력 하기*/
		}
	}
	destroyQueue(&que, sizeof(Person), personClear);
	return 0;
}
/*--------------------------------------------------------------------------------------------------------
Function name	: input() - 큐에 데이터를 반복적으로 입력 함
Parameters		: qPtr - 큐의 주소
Returns			: 없음
----------------------------------------------------------------------------------------------------------*/
void input(Queue *qPtr)
{
	//int enqueData;
	Person enqueData = { NULL,0,"" };
	char tmp[100];
	
	while (1) {
		printf("enqueue할 이름을 입력하시오 ('쫑' 입력 시 종료) : ");
		scanf("%s", tmp);
		if (!strcmp(tmp, "쫑")) {
			myFlush();
			break;
		}
		enqueData.name = (char*)malloc(sizeof(char)*(strlen(tmp) + 1));
		if (enqueData.name == NULL) return;
		strcpy(enqueData.name, tmp);

		printf("enqueue할 나이를 입력하시오 : ");
		scanf("%d", &enqueData.age);
		
		printf("enqueue할 번호를 입력하시오 : ");
		scanf("%s", enqueData.phoneNum);
		myFlush();
		if (!enqueue(qPtr, &enqueData, sizeof(Person), personMemcpy))
			printf("enqueue 실패!!\n");
	}
}
/*------------------------------------------------------------------------------------------------------------
Function name	: myDelete() - 큐에 데이터를 반복적으로 꺼냄
Parameters		: qPtr - 큐의 주소
Returns			: 없음
------------------------------------------------------------------------------------------------------------*/
void myDelete(Queue *qPtr)
{
	int i;
	int cnt; /* dequeue할 횟수를 입력 받아 저장할 변수*/
	//int dequeData; /* dequeue한 데이터를 저장할 변수*/
	Person dequeData = { NULL,0,"" };
	int res; /* dequeue()함수의 리턴값을 저장할 변수*/
	printf("Queue에서 데이터를 dequeue할 회수를 입력하시오: ");
	scanf("%d", &cnt);
	myFlush();

	for (i = 0; i<cnt; i++) {
		res = dequeue(qPtr, &dequeData,sizeof(Person),personMemcpy, personClear);
		if (res == 1) /* 성공적으로 get 작업을 수행 했으면*/
		{
			personPrint(&dequeData);
			//printf("dequeue 데이터: %5d\n", dequeData);
		}
		else
			printf("dequeue 실패!\n");
	}
}
/*------------------------------------------------------------------------------------------------------------
Function name	: menu() - 메뉴를 출력하고 메뉴번호를 입력 받아 리턴 함
Parameters		: menuLIst - 메뉴 출력할 문자열
menuCnt - 메뉴 개수
Returns			: 선택된 메뉴번호
------------------------------------------------------------------------------------------------------------*/
int menu(const char **menuList, int menuCnt)
{
	int i;
	int menuNum = 0; /* 입력된 메뉴번호 저장 변수*/
	int res; /* scanf()함수의 리턴값 저장 변수*/
	for (i = 0; i<menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}
	while (menuNum<1 || menuNum>menuCnt) /* 메뉴번호 범위의 번호가 입력시 까지 반복*/
	{
		printf("# 메뉴번호를 입력하세요 : ");
		res = scanf("%d", &menuNum);
		if (res != 1) /* 정수가 입력되지 않았으면*/
		{
			myFlush(); /* 입력버퍼 비우기*/
			continue;
		}
	}
	return menuNum;
}

/*------------------------------------------------------------------------------------------------------------
Function name	: myFlush() - 입력버퍼 지우기
Parameters		: 없음
Returns			: 없음
------------------------------------------------------------------------------------------------------------*/
void myFlush()
{
	while (getchar() != '\n')
	{
		;
	}
}
