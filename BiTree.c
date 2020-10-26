#pragma once
#include <stdio.h>
//#include <iostream>
#include <malloc.h>

#define ElemType char
#define Max_num 100
#define Status int
#define false 0
#define true 1

typedef struct BiNode
{
	ElemType data;
	struct BiNode* lchild, * rchild;
	int count;
	//平衡二叉树的平衡因子
	int ltag, rtag;
	//线索二叉树的
}BiNode,*BiTree;


/*-----------用于线索化二叉树的-----------*/

/* void InThread(BiTree& p, BiTree& pre)
 //中序遍历对二叉树线索化的递归算法
{
	if (p != NULL)
	{
		InThread(p->lchild, pre);
		if (p->lchild == NULL)
		{
			p->lchild = pre;
			p->ltag = 1;
		}

		//InThread(p->rchild, pre);
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}
*/

/*
void CreateInThread(BiTree& T)
//利用中序遍历建立线索二叉树
{
	BiTree pre = NULL;
	if (T != NULL)
		//非空才进行线索化
	{
		InThread(T, pre);	//	递归线索化
		pre->rchild = NULL;	//处理遍历的最后一结点
		pre->rtag = 1;
	}
}
*/

//1、使用先序遍历的方式建立一棵二叉树。

/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng 01.dot -o 01.png
*/

////非递归实现
void CreatBiTree01(BiNode* T, ElemType* num)
{
	if (T == NULL || num[0] == '#' || num[0] == '\0')
		puts("创建失败!");

	T->data = num[0];
	
	BiTree p = (BiTree)malloc(sizeof(BiNode));
	T->lchild = p;


	BiTree z[Max_num];
	int top = 0;
	z[top++] = T;

	int i = 1;
	while (num[i] != '\0')
	{
		//p = p->lchild;
		if (num[i] == '#')
		{
			p = NULL;

			p = z[--top];
			if (top < 0)
				break;
			//BiTree q = (BiTree)malloc(sizeof(BiNode));
			//p->rchild = q;
			p = p->rchild;
		}
		else
		{
			BiTree q = (BiTree)malloc(sizeof(BiNode));
			//q->lchild = NULL;
			//q->rchild = NULL;
			q->data = num[i];
			p->lchild = q;
			z[top++] = p;
			p = p->lchild;
		}
		i++;
	}
}

//递归实现
BiTree CreatBiTree(ElemType* num, int* i)
{
	BiTree T = (BiTree)malloc(sizeof(BiNode));
	int j = *i;
	if (num[j] == '#')
	{
		T = NULL;
		j++;
	}
	else
	{
		T->data = num[j++];
		T->ltag = 0;
		T->rtag = 0;
		*i = j;
		T->lchild = CreatBiTree(num, i);
		(*i)++;
		T->rchild = CreatBiTree(num, i);
	}
	return T;
}

//先序遍历二叉树
void visit_preorder(BiTree T)
{
	if (NULL != T)
	{
		printf("%c ",T->data);
		visit_preorder(T->lchild);
		visit_preorder(T->rchild);
	}
}

//中序遍历二叉树
void visit_midorder(BiTree T)
{
	if (NULL != T)
	{
		visit_midorder(T->lchild);
		printf("%c ",T->data);
		visit_midorder(T->rchild);
	}
}

//后序遍历二叉树
void visit_postorder(BiTree T)
{
	if (NULL != T)
	{
		visit_postorder(T->lchild);
		visit_postorder(T->rchild);
		printf("%c ",T->data);
	}
}

int main()
{
	char string[] = "AB##C##";
	int i = 0;
	char *defBit = string;

	BiTree T = NULL;
	T = CreatBiTree(defBit,&i);
	
	puts("先序遍历：");
	visit_preorder(T);
	puts("");

	puts("中序遍历：");
	i = 0;
	visit_midorder(T);
	puts("");

	puts("后序遍历：");
	i = 0;
	visit_postorder(T);
	puts("");
	return 0;
}
