#include "arrayStack.h"
#include <stdio.h>
#include <malloc.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - ������ ũ���� ������ �����ϴ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  size - ������ ũ��
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createStack(Stack *sp, int size, size_t dataSize)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	sp->stack = calloc(size, dataSize);  /* stack �޸� �Ҵ� */
	if (sp->stack != NULL) {	/* stack �޸� �Ҵ� ���� ��*/
		sp->size = size;	/* ���� size �ʱ�ȭ */
		sp->top = 0;		/* top 0���� �ʱ�ȭ */
		return TRUE;
	}
	else {	/* stack �޸� �Ҵ� ���� �� */
		return FALSE;
	}
}
/*-----------------------------------------------------------------------------------
Function name	: isStackFull - ������ �� ���ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ �� �������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
BOOL isStackFull(Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if (sp->top == sp->size)  /* stack�� �� �������� */
		return TRUE;
	else
		return FALSE;
}
/*-----------------------------------------------------------------------------------
Function name	: isStackEmpty - ������ ������ ����ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ ������ ��������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
BOOL isStackEmpty(Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if (sp->top == 0)  /* stack�� ��������� */
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: push - ���ÿ� ������ �ϳ��� ������
Parameters		: sp - ���ð��� ����ü�� �ּ�
inData - ���ÿ� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL push(Stack *sp, void *inData, size_t size, void(*memcpy)(void *, void*))
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if (isStackFull(sp)) {  /* stack�� �� �������� */
		return FALSE;
	}
	else {					/* �����͸� top ��ġ�� ������ �� top�� ������Ŵ */
		memcpy((char*)sp->stack + (size * sp->top), inData);
		sp->top++;
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: pop - ���ÿ��� ������ �ϳ��� ����
Parameters		: sp - ���ð��� ����ü�� �ּ�
popData -  ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL pop(Stack * sp, void *popData, size_t size, void(*dataClear)(void *), void (*memcpy)(void *,void*))
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}

	if (isStackEmpty(sp)) {  /* stack�� ��������� */
		return FALSE;
	}
	else {	/* �����͸� top-1�� ��ġ���� ���� popData�� ����Ű�� ���� ���� �� */
		--sp->top;
		memcpy(popData, ((char*)sp->stack + (size * sp->top)));
		dataClear((char*)sp->stack + (size * sp->top));
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - ������ ��� ������ ���(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sp, size_t size, void(*dataPrint)(void*))
{
	int i = sp->top;
	if (sp == NULL) {  /* sp������ NULL check*/
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
Function name	: destroyStack -  ���� �Ҹ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp, size_t size, void(*dataClear)(void*))
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return;
	}
	if (sp->stack != NULL) {	/* statck���� ���Ǵ� �迭 �޸� ���� */
		while (sp->top--) {
			dataClear((char*)sp->stack + (size * sp->top));
		}
		free(sp->stack);
	}
	sp->stack = NULL;	/* stack ����� NULL pointer�� �ʱ�ȭ */
	sp->size = 0;		/* size�� top����� 0���� �ʱ�ȭ */
	sp->top = 0;
}
