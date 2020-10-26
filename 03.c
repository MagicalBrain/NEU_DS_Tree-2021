/*
* author:HRL
*
* date:10/09/2020
* 
* description:
* 3、求一棵二叉树的结点个数。
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>

int func03(BiTree T)
{
	if (NULL != T)
	{
		return func03(T->lchild) + func03(T->rchild) + 1;
	}
	return 0;
}

int main()
{
	char string[] = "AB##CD##E##";
	//char string[] = "AB##C##";
	BiTree T1  = NULL, T2 = NULL, T3 = NULL;
	int *id,start_id = 0;
	id = &start_id;

	T1 = CreatBiTree(string,id);

	visit_preorder(T1);
	puts("");

	printf("二叉树有%d个结点\n",func03(T1));
	//Tree2dot(T1);
	return 0;
}


