/*
* author:HRL
*
* date:10/09/2020
* 
* description:
* 7、求一棵二叉树的高度。
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

int func07(BiTree T)
{
	if (NULL != T)
	{
		return ( (func07(T->lchild) > func07(T->rchild)) ? func07(T->lchild) : func07(T->rchild)) + 1;	
	}
	return 0;
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

	printf("二叉树的高度为%d\n",func07(T1));
	Tree2dot(T1);
	return 0;
}
