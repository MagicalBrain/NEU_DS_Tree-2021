/*
* author:HRL
*
* date:10/11/2020
* 
* description:
* 11、设计算法，利用叶子结点中的空指针域将所有叶子结点链接成一个带头结点的双链表。
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

//非递归的先序遍历
void func1101(BiTree T)
{
	BiTree s[Max_num];
	int top = 0;
	
	BiNode *p = T;
	while (NULL != p || top != 0)
	{	
		while (NULL != p)
		{
			if (NULL != p->rchild)
				s[top++] = p;
			printf("%c ",p->data);

			p = p->lchild;
						
		}
		if (top > 0)
			p = s[--top]->rchild;

	}
}


void insert_leaves(BiTree T, BiTree &L)
{
	if (NULL != T)
	{
		if (NULL == T->lchild && NULL == T->rchild)
		{
			printf("%c\n",T->data);
			T->lchild = L;
			T->rchild = L->rchild;
			L->rchild = T;
			T->rchild->lchild = T;
		}
		else
		{
			insert_leaves(T->lchild,L);
			insert_leaves(T->rchild,L);
		}
	}
}

BiTree func11(BiTree T)
{
	if (NULL != T)
	{
		BiTree L = (BiTree) malloc (sizeof(BiNode));
		L->lchild = NULL;
		L->rchild = NULL;

	 	insert_leaves(T,L);
		return L;
	}
	else
		return NULL;
}

/*void print_func11(BiTree T)
{
	T = T->lchild;
	while(NULL != T)
	{
		printf("%c ", T->data);
		T = T->lchild;
	}
}*/

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

	//Tree2dot(T1);

	T2 = (BiTree) malloc (sizeof(BiNode));
	T2 = func11(T1);
	if (NULL != T2)
	{
//		print_func11(T2);
		puts("");
		puts("处理成功！");
		
		Tree2dot(T1);
	}
	else
		puts("处理失败！");
	//puts("");
	
	return 0;
}
