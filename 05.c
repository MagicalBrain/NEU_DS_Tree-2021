/*
* author:HRL
*
* date:10/09/2020
* 
* description:
* 5、求一棵二叉树中度为1的结点个数。
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

int func05(BiTree T)
{
	if (NULL != T)
	{
		if (NULL != T->rchild && NULL != T->lchild)
			return func05(T->lchild) + func05(T->rchild);
		else if (NULL != T->rchild && NULL == T->lchild)
			return func05(T->rchild) + 1;
		else if (NULL == T->rchild && NULL != T->lchild)
			return func05(T->lchild) + 1;
		else return 0;
	}
	return 0;
}

int main()
{
	char string[] = "AB##CD##E##";
	//char string[] = "ABC##D###";
	//char string[] = "AB#C#D##E##";
	//char string[] = "AB##C##";
	//char string[] = "ABC##D##EF###";
	BiTree T1  = NULL, T2 = NULL, T3 = NULL;
	int *id,start_id = 0;
	id = &start_id;

	T1 = CreatBiTree(string,id);

	visit_preorder(T1);
	puts("");

	printf("二叉树有%d个度为1的结点\n",func05(T1));
	Tree2dot(T1);
	return 0;
}

