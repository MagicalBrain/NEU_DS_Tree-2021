/*
* author:HRL
*
* date:10/09/2020
* 
* description:
* 4、求一棵二叉树的叶子结点个数。
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

int func04(BiTree T)
{
	if (NULL != T)
	{
		if (NULL == T->rchild && NULL == T->lchild)
			return 1;

		return func04(T->lchild) + func04(T->rchild);
	}
	return 0;
}

int main()
{
	//char string[] = "AB##CD##E##";
	//char string[] = "AB##C##";
	char string[] = "ABC##D##EF###";
	BiTree T1  = NULL, T2 = NULL, T3 = NULL;
	int *id,start_id = 0;
	id = &start_id;

	T1 = CreatBiTree(string,id);

	visit_preorder(T1);
	puts("");

	printf("二叉树有%d个叶子结点\n",func04(T1));
	Tree2dot(T1);
	return 0;
}

