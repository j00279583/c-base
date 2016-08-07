#include "BinTree.h"

BinTree_ST * Agent_CreateBitTree(BinTree_ST *pTreeNode)
{	
	char ch;
	char chSpace;
	
	scanf("%c",&ch);
	scanf("%c",&chSpace); //½«¿Õ¸ñ¼ü¹ýÂËµô

	if (ch == '#')
	{
		pTreeNode = NULL;	

	}
	else
	{
	    pTreeNode = (BinTree_ST *)malloc(sizeof(BinTree_ST));
		if (pTreeNode == NULL)
		{
			printf("malloc failed \r\n");
		}

		memset(pTreeNode, 0 ,sizeof(pTreeNode));
		pTreeNode->pLchild =NULL;
		pTreeNode->pRchild =NULL;
		
		pTreeNode->chData= ch;

		pTreeNode->pLchild = Agent_CreateBitTree(pTreeNode->pLchild);
		pTreeNode->pRchild = Agent_CreateBitTree(pTreeNode->pRchild);
	}

	return pTreeNode;
}


BinTree_ST * Agent_PreorderBiTree(BinTree_ST *pTreeNode)
{		
	if (pTreeNode != NULL)
	{
		printf("the data is %c \r\n",pTreeNode->chData);
		
		Agent_PreorderBiTree(pTreeNode->pLchild);
		Agent_PreorderBiTree(pTreeNode->pRchild);
		
	}
		
	return pTreeNode;	
}


BinTree_ST * Agent_InorderBiTree(BinTree_ST *pTreeNode)
{		
	if (pTreeNode != NULL)
	{		
		Agent_InorderBiTree(pTreeNode->pLchild);
		
		printf("the data is %c \r\n",pTreeNode->chData);
		
		Agent_InorderBiTree(pTreeNode->pRchild);
		
	}
	
	return pTreeNode;
}

BinTree_ST * Agent_PostorderBiTree(BinTree_ST *pTreeNode)
{		
	if (pTreeNode != NULL)
	{		
		Agent_PostorderBiTree(pTreeNode->pLchild);
		Agent_PostorderBiTree(pTreeNode->pRchild);
		printf("the data is %c \r\n",pTreeNode->chData);
		
	}
	
	return pTreeNode;
}


int Agent_SumLeafBinTree(BinTree_ST *pTreeNode)
{	

	if (pTreeNode == NULL)
	{
		return 0;
	}
	
	if((pTreeNode->pLchild == NULL) && (pTreeNode->pRchild == NULL))
	{
		return 1;
	}

	return Agent_SumLeafBinTree(pTreeNode->pLchild) + 
		Agent_SumLeafBinTree(pTreeNode->pRchild);

}


int Agent_GetDepthOfBinTree(BinTree_ST *pTreeNode)
{	
	int iLeftLength = 0;
	int iRightLength = 0;
	
	if (pTreeNode == 0)
	{
		return 0;


	}

	iLeftLength= Agent_GetDepthOfBinTree(pTreeNode->pLchild);
	iRightLength= Agent_GetDepthOfBinTree(pTreeNode->pRchild);

	
	return (iLeftLength>iRightLength)?(iLeftLength+1):(iRightLength+1);


}

int main(int argc, int *argv[])
{	
	BinTree_ST *pBitTree;
	int iSum = 0;
	int iDepth = 0;

	printf("Print Please input the tree data: \r\n");
	printf("' # 'stands for NULL Tree \r\n");
	
	pBitTree = Agent_CreateBitTree(pBitTree);
	
	printf("Preorder of the tree \r\n");
	Agent_PreorderBiTree(pBitTree);
	printf("\r\n \r\n");
	
	printf("Inorder of the tree \r\n");
	Agent_InorderBiTree(pBitTree);
	printf("\r\n \r\n");

	
	printf("Postorder of the tree \r\n");
	Agent_PostorderBiTree(pBitTree);
	printf("\r\n \r\n");

	iSum = Agent_SumLeafBinTree(pBitTree);
	printf("Leaf number is = 0x%x \r\n",iSum);


	iDepth = Agent_GetDepthOfBinTree(pBitTree);
	printf("Depth of the tree is = 0x%x \r\n",iDepth);
	
	return 0;
}
