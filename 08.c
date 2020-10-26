/*
* author:HRL
*
* date:10/11/2020
* 
* description:
* 8、求一棵二叉树中值为x的结点作为根结点的子树深度。
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"


int get_level(BiTree T)
{
	if (NULL != T)
	{
		int l_height = get_level(T->lchild);
		int r_height = get_level(T->rchild);
		return (l_height > r_height) ? l_height + 1 : r_height + 1;
	}
	return 0;
}

BiTree find_item(BiTree T, ElemType x)
{
	if (NULL != T)
	{
		if (x == T->data)
			return T;
		else
		{
		
			if (NULL != find_item(T->lchild,x))
			{
				T = find_item(T->lchild,x);
				return T;
			}	
			if (NULL != T->rchild)
				return find_item(T->rchild,x);
			
		}
	}
	return NULL;
}

int func08(BiTree T, ElemType x)
{
	BiTree f = find_item(T,x);
	if (NULL == f)
		return 0;
	return (get_level(f));
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

	puts("请输入根结点的值：");
	ElemType x;
	x = getchar();
	getchar();

	printf("二叉树的以%c为根结点的子树深度为%d\n",x,func08(T1,x));
	Tree2dot(T1);
	return 0;
}
