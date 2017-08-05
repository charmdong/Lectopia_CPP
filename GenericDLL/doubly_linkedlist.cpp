#include "doublyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()
/*----------------------------------------------------------------------------------
Function name	: createList - 연결 리스트 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	if (lp == NULL) {  /* lp포인터 NULL check */
		return FALSE;
	}
	lp->head = (Node *)calloc(1,sizeof(Node));	/* head node 생성 */
	if (lp->head == NULL) {
		return FALSE;
	}
	lp->tail = (Node *)calloc(1,sizeof(Node));	/* tail node 생성 */
	if (lp->tail == NULL) {
		free(lp->head);
		return FALSE;
	}

	lp->head->next = lp->tail; /* head node와 tail node 연결 */
	lp->tail->prev = lp->head; 
	lp->head->prev = lp->head; /* head node의 prev는 자기 자신을 가리키도록 설정 */
	lp->tail->next = lp->tail; /* tail node의 next는 자기 자신을 가리키도록 설정 */
	lp->size = 0;	/* 연결 리스트 크기 0으로 초기화 */

	return TRUE;
}
/*----------------------------------------------------------------------------------
Function name	: addFirst - head node 뒤에 node 추가(역순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, void *data, size_t size, void(*memcpy)(void *, void *))
{
	Node *newp;

	if (lp == NULL) { /* lp포인터 NULL check */
		return FALSE;
	}

	newp = (Node *)calloc(1, sizeof(Node) + size); /* 새 노드 생성 */
	if (newp != NULL) {		/* 새 노드 생성 성공 시 처리 */
		//newp->data = data;				/* 새 노드에 data 저장 */
		memcpy(newp + 1, data);
		newp->prev = lp->head;			/* 새 노드의 prev 설정 */
		newp->next = lp->head->next;	/* 새 노드의 next 설정 */
		lp->head->next->prev = newp;	/* 새 노드의 뒷 노드가 새 노드를 가리키도록 설정*/
		lp->head->next = newp;			/* head ndoe 뒤에 새 노드 연결 */
		++lp->size;						/* 리스트 size 증가 */
		return TRUE;
	}
	else {					/* 새 노드 생성 실패 시 처리 */
		return FALSE;
	}
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node 앞에 새 node 추가(정순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, void *data, size_t size, void(*memcpy)(void *, void *))
{
	Node *newp;	/* 새 노드 주소저장용 포인터 */
	
	if (lp == NULL) { /* lp포인터 NULL check */
		return FALSE;
	}

	newp = (Node *)calloc(1,sizeof(Node)+size);	/* 새 노드 생성 */
	if (newp != NULL) {	/*  새 노드 생성 성공 시 처리 */
		//newp->data = data;				/* 새 노드에 data 저장 */
		memcpy(newp+1, data);
		newp->prev = lp->tail->prev;	/* 새 노드의 prev 설정 */
		newp->next = lp->tail;			/* 새 노드의 next 설정 */
		lp->tail->prev->next = newp;	/* 새 노드의 앞 노드가 새 노드를 가리키도록 설정 */
		lp->tail->prev = newp;			/* tail ndoe 앞에 새 노드 연결 */
		++lp->size;						/* 리스트 size 증가 */
		return TRUE;
	}
	else {	/* 새 노드 생성 실패 시 처리 */
		return FALSE;
	}
}
/*----------------------------------------------------------------------------------
Function name	: displayList - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void displayList(List *lp, void(*dataPrint)(void *))
{
	Node *curp;
	if (lp == NULL) { /* lp포인터 NULL check */
		return;
	}

	curp = lp->head->next;  /* data 있는 첫노드를 curp로 가리키게 함 */
							/* 리스트의 마지막 노드까지 curp를 옮기면서 data영역 출력하기 */
	while (curp != lp->tail) {
		//printf("%8d\n", curp->data);
		dataPrint(curp + 1);
		curp = curp->next;
	}
	printf("\n");
	return;
}
/*----------------------------------------------------------------------------------
Function name   : searchNode - data와 일치하는 첫 번째 node 검색
Parameters      : lp - 리스트 관리 구조체의 주소
data - 검색할 데이터
Returns         : 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, void *data, int(*dataCompare)(void *, void*))
{
	Node *curp;
	if (lp == NULL) { /* lp포인터 NULL check */
		return NULL;
	}

	curp = lp->head->next;  /* data 있는 첫노드를 curp로 가리키게 함 */
							/* 리스트의 마지막 데이터 노드까지 curp를 옮기면서 검색하기 */
	while (curp != lp->tail) {
		//if (curp->data == data) {
		if (!dataCompare(curp+1, data)) {
			return curp;   /* 찾은 노드의 주소 리턴 */
		}
		else {
			curp = curp->next;
		}
	}
	return NULL;   /* 못찾으면 NULL pointer 리턴 */
}
/*----------------------------------------------------------------------------------
Function name   : removeNode - data와 일치하는 첫 번째 노드 삭제
Parameters      : lp - 리스트 관리 구조체의 주소
data - 삭제할 데이터
Returns         : 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, void* data, int(*dataCompare)(void *,void*), void(*dataClear)(void *))
{
	Node *delp;

	if (lp == NULL) { /* lp포인터 NULL check */
		return FALSE;
	}

	delp = searchNode(lp, data, dataCompare);  /* 삭제할 node를 검색 함 */
	if (delp != NULL) { /* 삭제할 노드를 찾았으면 삭제하기 */
						/* 삭제할 노드의 앞 노드와 삭제할 노드의 뒷 노드를 연결*/
		delp->prev->next = delp->next;
		delp->next->prev = delp->prev;
		dataClear(delp + 1);
		free(delp);   /* 노드 삭제 */
		--lp->size;   /* 리스트 size 감소 */
		return TRUE;
	}
	else {   /* 삭제할 노드의 못찾았으면 삭제 실패 */
		return FALSE;
	}
}
/*----------------------------------------------------------------------------------
Function name   : sortList - 노드 정렬(오름차순)
Parameters      : lp - 리스트 관리 구조체의 주소
Returns         : 없음
----------------------------------------------------------------------------------*/
void sortList(List *lp, size_t size, int(*dataCompare)(void *, void*), void(*memcpy)(void *, void*),void(*dataClear)(void *))
{
	Node *curp;
	Node *nextp;
	Node *temp;

	if (lp == NULL) { /* lp포인터 NULL check */
		return;
	}

	temp = (Node*)calloc(1, sizeof(Node) + size);

	curp = lp->head->next;
	while (curp->next != lp->tail) {
		nextp = curp->next;
		while (nextp != lp->tail) {
			if (dataCompare(curp+1,nextp+1)> 0) {
				memcpy(temp+1, curp+1);
				memcpy(curp+1, nextp+1);
				memcpy(nextp+1, temp+1);
			}
			nextp = nextp->next;
		}
		curp = curp->next;
	}
	dataClear(temp+1);
	free(temp);
}
/*----------------------------------------------------------------------------------
Function name   : destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
Parameters      : lp - 리스트 관리 구조체의 주소
Returns         : 없음
----------------------------------------------------------------------------------*/
void destroyList(List *lp, void(*dataClear)(void *))
{
	Node *curp;
	Node *nextp;
	if (lp == NULL) { /* lp포인터 NULL check */
		return;
	}
	curp = lp->head->next;
	while (curp != lp->tail) {
		nextp = curp->next;
		dataClear(curp + 1);
		free(curp);
		curp = nextp;
	}
	free(lp->head);
	free(lp->tail);

	lp->head = lp->tail = NULL;
	lp->size = 0;
	return;
}