#include "arrayStack.h"
#include <stdio.h>
#include <malloc.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - 지정된 크기의 스택을 생성하는 함수
Parameters		: sp - 스택관리 구조체의 주소
				  size - 스택의 크기
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL createStack(Stack *sp, int size, size_t dataSize)
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}
	sp->stack = calloc(size, dataSize);  /* stack 메모리 할당 */
	if (sp->stack != NULL) {	/* stack 메모리 할당 설공 시*/
		sp->size = size;	/* 스택 size 초기화 */
		sp->top = 0;		/* top 0으로 초기화 */
		return TRUE;
	}
	else {	/* stack 메모리 할당 실패 시 */
		return FALSE;
	}
}
/*-----------------------------------------------------------------------------------
Function name	: isStackFull - 스택이 꽉 차있는지 검사
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 스택이 꽉 차있으면 TRUE, 아니면 FALSE 리턴
-----------------------------------------------------------------------------------*/
BOOL isStackFull(Stack *sp)
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}
	if (sp->top == sp->size)  /* stack이 꽉 차있으면 */
		return TRUE;
	else
		return FALSE;
}
/*-----------------------------------------------------------------------------------
Function name	: isStackEmpty - 스택이 완전히 비어있는지 검사
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 스택이 완전히 비어있으면 TRUE, 아니면 FALSE 리턴
-----------------------------------------------------------------------------------*/
BOOL isStackEmpty(Stack *sp)
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}
	if (sp->top == 0)  /* stack이 비어있으면 */
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: push - 스택에 데이터 하나를 저장함
Parameters		: sp - 스택관리 구조체의 주소
inData - 스택에 저장할 데이터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL push(Stack *sp, void *inData, size_t size, void(*memcpy)(void *, void*))
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}
	if (isStackFull(sp)) {  /* stack이 꽉 차있으면 */
		return FALSE;
	}
	else {					/* 데이터를 top 위치에 저장한 후 top을 증가시킴 */
		memcpy((char*)sp->stack + (size * sp->top), inData);
		sp->top++;
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: pop - 스택에서 데이터 하나를 꺼냄
Parameters		: sp - 스택관리 구조체의 주소
popData -  꺼낸 데이터를 저장할 기억공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL pop(Stack * sp, void *popData, size_t size, void(*dataClear)(void *), void (*memcpy)(void *,void*))
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}

	if (isStackEmpty(sp)) {  /* stack이 비어있으면 */
		return FALSE;
	}
	else {	/* 데이터를 top-1번 위치에서 꺼내 popData가 가리키는 곳에 저장 함 */
		--sp->top;
		memcpy(popData, ((char*)sp->stack + (size * sp->top)));
		dataClear((char*)sp->stack + (size * sp->top));
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - 스택의 모든 데이터 출력(pop하면 나오는 순서대로 출력)
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sp, size_t size, void(*dataPrint)(void*))
{
	int i = sp->top;
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return;
	}
	while (i != 0)
	{
		dataPrint((char*)sp->stack + (size *(i - 1)));
		i--;
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyStack -  스택 소멸 함수
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp, size_t size, void(*dataClear)(void*))
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return;
	}
	if (sp->stack != NULL) {	/* statck으로 사용되는 배열 메모리 해제 */
		while (sp->top--) {
			dataClear((char*)sp->stack + (size * sp->top));
		}
		free(sp->stack);
	}
	sp->stack = NULL;	/* stack 멤버를 NULL pointer로 초기화 */
	sp->size = 0;		/* size와 top멤버를 0으로 초기화 */
	sp->top = 0;
}
