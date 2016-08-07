#include "queue.h"

int Agent_InitQueue(QueueData_ST *stQueue)
{
	stQueue->front = stQueue->rear = 0;
	stQueue->pBase = (int *)malloc(sizeof(MAX_LENGTH));
	
	return VOS_OK;
}

int Agent_EntherQueue(QueueData_ST *pstQueue, int iData)
{
	if (((pstQueue->rear+1) % MAX_LENGTH) == pstQueue->front)
	{
		printf("Sorry OverFlow ,can not input the data:\r\n");
		return VOS_ERROR;
	}

	pstQueue->pBase[pstQueue->rear] = iData;
	
	pstQueue->rear = (pstQueue->rear + 1) % MAX_LENGTH;

	return VOS_OK;
}

int Agent_LeaveQueue(QueueData_ST *pstQueue, int *piData)
{
	if (pstQueue->rear == pstQueue->front)
	{
		printf("Sorry ,the queue is empty !\r\n");
		return VOS_ERROR;
	}

	*piData = pstQueue->pBase[pstQueue->front];
	pstQueue->front = (pstQueue->front + 1 )% MAX_LENGTH;

	return VOS_OK;
}

int main(int agrc, int *argv[])
{	
	int iData = 0;
	
	QueueData_ST stQueue = { 0 };
	
	Agent_InitQueue(&stQueue);

	printf("Please input the data 0 --7 into queue\r\n");
	
	for (int i = 0; i < 8; i++)
	{	
		printf("the enther data is = 0x%x\r\n",i);
		Agent_EntherQueue(&stQueue,i); 	
	}

	printf("\r\n\r\n\r\n");
		
	while(stQueue.rear != stQueue.front)
	{
		Agent_LeaveQueue(&stQueue,&iData);	
		
		printf("the leave data is = 0x%x\r\n",iData);
	}
	
	return VOS_OK;
}
