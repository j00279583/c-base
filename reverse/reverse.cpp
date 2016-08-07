#include "reverse.h"


ListNode *Agent_InitList()
{
	ListNode * pHeadNode = NULL;

	pHeadNode = (ListNode*)malloc(sizeof(ListNode));
	if (pHeadNode == NULL)
	{
		printf("malloc failed! \r\n");
		return NULL;
	}

	memset(pHeadNode, 0, sizeof(ListNode));
	pHeadNode->pNext = NULL;
	
	return pHeadNode;
	
}


ListNode *Agent_InSertList(ListNode *pHead, int data)
{	
	ListNode *pNewNode = NULL;
	ListNode *pTempHead = NULL;
	ListNode *pLasNode = NULL;

	if (pHead ==NULL)
	{
		printf("ptr is NULL");
	}

	pLasNode = pTempHead = pHead;

	while(pTempHead->pNext !=NULL)
	{
		pTempHead = pTempHead->pNext;
		pLasNode = pTempHead;
	}

	pNewNode = (ListNode*)malloc(sizeof(ListNode));
	if (pNewNode == NULL)
	{
		printf("malloc failed! \r\n");
		return NULL;
	}

	memset(pNewNode, 0, sizeof(ListNode));
	pNewNode->pNext = NULL;

	pNewNode->data = data;
	pLasNode->pNext = pNewNode;
	
	return pHead;
}

ListNode *Agent_PrintfList(ListNode *pHead)
{
	ListNode *pTempHead = NULL;
	pTempHead = pHead->pNext;

	while(pTempHead != NULL)
	{
		printf("the data is = 0x%x \r\n",pTempHead->data);	
		pTempHead = pTempHead->pNext;
	}
	
	return pHead;
}


ListNode *Agent_ReverseList(ListNode *pHead)
{	
	ListNode * pCur = NULL;
	ListNode * pNext = NULL;
	ListNode * pPre = NULL;

	if (pHead ==NULL)
	{
		printf("ptr is NULL");
	}

	pCur = pHead->pNext;

	while(pCur != NULL)
	{
		pNext = pCur->pNext;
		pCur->pNext = pPre;
		pPre = pCur;
		
		pCur = pNext;
	}

	pHead->pNext = pPre;
	
	
	return pHead;
}
void main()
{	
	ListNode *pListHead = NULL;
	pListHead = Agent_InitList();
	if (pListHead == NULL)
	{
		printf("here return error\r\n");
	}

	for (int i = 0; i< 5;i ++)
	{
		Agent_InSertList(pListHead,i);
	}

	Agent_PrintfList(pListHead);
	
    printf("After reverse: \r\n");

	Agent_ReverseList(pListHead);
	Agent_PrintfList(pListHead);

	
}
