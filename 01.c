/*
* author:HRL
*
* date:10/04/2020
* 
* description:
* 1、使用先序遍历的方式建立一棵二叉树。
*/

#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

void visit_preorder(BiTree T)
{
	if (NULL != T)
	{
		if (T->data != '#')	
			printf("%c ",T->data);
		visit_preorder(T->lchild);
		visit_preorder(T->rchild);
		
//		return true;
	}
//	return false;
}

//利用先序遍历来创建一棵二叉树
BiTree func01(char Bidef[], int * i)
{
	BiNode *t = NULL;
	ElemType data;
	
	data = Bidef[*i];
	(*i) +=1;
	if ('#' != data)
	{
		t = (BiNode*) malloc (sizeof(BiNode));
		t->data = data;
		//i+=1;
		t->lchild = func01(Bidef,i);
		//i+=1;
		t->rchild = func01(Bidef,i);
	}
	return t;
}

int main()
{
	char string[] = "AB##CD##E##";
	//char string[] = "AB##C##";
	BiTree T1  = NULL, T2 = NULL, T3 = NULL;
	int *id,start_id = 0;
	id = &start_id;

	T1 = func01(string,id);

	visit_preorder(T1);
	puts("");

	Tree2dot(T1);
	return 0;
}
