/*
* author:HRL
*
* date:10/09/2020
* 
* description:
* 6、求一棵二叉树中值为x的结点，
* 若存在则返回存储位置；
* 不存在则返回空。
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

BiTree func06(BiTree T,ElemType x)
{
	BiTree re = NULL;
	if (NULL != T)
	{
		if (T->data  == x)
		{
			return  T;
		}
		if (NULL != func06(T->lchild,x) )
			return func06(T->lchild,x);
		if (NULL != T->rchild)
			return func06(T->rchild,x);
	}
	return NULL;
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

	ElemType x;
	puts("请输入要查找的值x：");
	x = getchar();
	getchar();

	T2 = func06(T1,x);
	if (NULL != T2)
		printf("二叉树中该结点地址为：%d\n", T2->data);
	else
		puts("未找到！");
	Tree2dot(T1);
	return 0;
}
