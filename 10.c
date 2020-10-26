/*
* author:HRL
*
* date:10/11/2020
* 
* description:
* 10、判断两棵二叉树是否相似。
* 相似：返回TRUE
* 不相似：返回FALSE
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

Status func10(BiTree T1, BiTree T2)
{
	if ( (NULL != T1 && T2 == NULL)
	|| (NULL == T1 && NULL != T2))
		return false;
	if (NULL == T1 && NULL == T2)
		return true;
	else{
		if (func10(T1->lchild,T2->lchild))
			return func10(T1->rchild,T2->rchild);
		else
			return false;
	}
}

int main()
{
	//char string1[] = "AB##CD##E##";
	char string1[] = "ABC##D##EF###";
	//char string1[] = "ABC##D###";
	//char string1[] = "AB#C#D##E##";
	//char string1[] = "AB##C##";
	
	char string2[] = "ABC##D##EF###";
	//char string2[] = "ABC##D###";
	//char string2[] = "AB#C#D##E##";
	//char string2[] = "AB##C##";

	BiTree T1  = NULL, T2 = NULL, T3 = NULL;
	int *id,start_id = 0;
	id = &start_id;

	T1 = CreatBiTree(string1,id);

	*id = 0;
	T2 = CreatBiTree(string2,id);

	visit_preorder(T1);
	puts("");

	visit_preorder(T2);
	puts("");
	
	if (func10(T1,T2))
		puts("这两棵二叉树相似！");
	else
		puts("这两棵二叉树不相似！");

	Tree2dot(T1);
	Tree2dot(T2);

	return 0;
}
