#include "stack.h"



int Agent_InitStack(StackData_ST* pstStackData)
{	
	int *pTemp = NULL;
	
	pstStackData->SatckTop = -1;

	pTemp = (int *)malloc(sizeof(MAX_LENGTH+1));

	pstStackData->pBase = pTemp;

	return VOS_OK;
}

int Agent_PushData(StackData_ST* pstStackData, int iData)
{
	if ((pstStackData->SatckTop) == MAX_LENGTH)
	{
		printf("Sorry ,OverFlow, can not push data into Stack \r\n");
		return VOS_ERROR;
	}
	
	pstStackData->pBase[++pstStackData->SatckTop] = iData;

	return VOS_OK;	
}

int Agent_PopData(StackData_ST* pstStackData, int *piData)
{
	if ((pstStackData->SatckTop) == (-1))
	{
		printf("the stack is Empty \r\n");
		return VOS_ERROR;
	}

	*piData = pstStackData->pBase[pstStackData->SatckTop--];

	return VOS_OK;
}

int main(int agrc, int *argv[])
{	
	int iData = 0;
	
	StackData_ST stStackData = {0};
	
	Agent_InitStack(&stStackData);

	printf("Please input the data 0 --7 into stack\r\n");
	for (int i = 0; i < 8; i++)
	{	
		printf("the enther data is = 0x%x\r\n",i);
		Agent_PushData(&stStackData,i); 	
	}

	printf("Please pop the data \r\n\r\n");
	while(stStackData.SatckTop >=0)
	{
		Agent_PopData(&stStackData,&iData);		
		printf("the data is = 0x%x\r\n",iData);
	}
	
	return 0;
}
