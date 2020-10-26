/*
* author:HRL
*
* date:10/09/2020
* 
* description:
* 练习：使用层次遍历序列和中序序列来建立一棵二叉树。
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
		
	}
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
