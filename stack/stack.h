#include <stdio.h>
#include <malloc.h>
#include <string.h>


#define MAX_LENGTH 100
#define VOS_OK 0
#define VOS_ERROR 0xFFFF

typedef struct Tag_StackData
{
	int  SatckTop;
	int *pBase;
}StackData_ST;



