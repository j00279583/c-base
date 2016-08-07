#include <stdio.h>
#include <malloc.h>
#include <string.h>


typedef struct Tag_BinTree
{
	char chData;
	struct Tag_BinTree *pLchild;
	struct Tag_BinTree *pRchild;
}BinTree_ST;

