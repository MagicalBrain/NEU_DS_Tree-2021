/*
* author:HRL
*
* date:10/11/2020
* 
* description:
* 9、交换一棵二叉树的左右子树。
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

void func09(BiTree T)
{
	if (NULL != T)
	{
		BiTree t = T->lchild;
		T->lchild = T->rchild;
		T->rchild = t;
		func09(T->lchild);
		func09(T->rchild);
	}
}

int main()
{
	//char string[] = "AB##CD##E##";
	//char string[] = "ABC##D###";
	//char string[] = "AB#C#D##E##";
	//char string[] = "AB##C##";
	char string[] = "ABC##D##EF###";
	BiTree T1  = NULL, T2 = NULL, T3 = NULL;
	int *id,start_id = 0;
	id = &start_id;

	T1 = CreatBiTree(string,id);

	visit_preorder(T1);
	puts("");

	Tree2dot(T1);

	func09(T1);
	Tree2dot(T1);
	return 0;
}
