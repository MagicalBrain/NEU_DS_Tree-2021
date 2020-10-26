/*
* author:HRL
*
* date:10/12/2020
* 
* description:
* 12、假设一个仅包含二元运算的算术表达式以二叉链表的形式存储在二叉树T里。
* 设计算法求表达式的值
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

//先写一个递归的后序遍历
void func12(BiTree T,int i)
{
	if (NULL != T)
	{
		func12(T->lchild,i);
		func12(T->rchild,i);
		printf("%c ",T->data);
	}
}

int clc(char oprt,int l_num, int r_num)
{
	switch(oprt)
	{
	case '+':
		return l_num + r_num;
	case '-':
		return l_num - r_num;
	case '*':
		return l_num * r_num;
	case '/':
		return l_num / r_num;
	default:
		return 0;
	}
}

int func12(BiTree T)
{
	if (NULL != T)
	{
		if (NULL != T->lchild && NULL != T->rchild)
		{
			int l_num = func12(T->lchild);
			int r_num = func12(T->rchild);
			return clc(T->data,l_num,r_num);
		//printf("%c ",T->data);
		}
		else
			return T->data - '0';
	}
	
	return 0;
}

int main()
{
	//char string1[] = "AB##CD##E##";
	//char string1[] = "ABC##D##EF###";
	//char string1[] = "ABC##D###";
	//char string1[] = "AB#C#D##E##";
	//char string1[] = "AB##C##";
	char string[] = "++1##2##*3##/4##+5##6##";

	//char string[] = "ABC##D##EF###";
	//char string2[] = "ABC##D###";
	//char string2[] = "AB#C#D##E##";
	//char string2[] = "AB##C##";

	BiTree T1  = NULL, T2 = NULL, T3 = NULL;
	int *id,start_id = 0,re = 0;
	id = &start_id;

	T1 = CreatBiTree(string,id);

	
	visit_preorder(T1);
	puts("");	

	//func12(T1,0);
	//Tree2dot(T1);
	re = func12(T1);
	printf("result: %d\n",re);
	return 0;
}
