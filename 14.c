/*
* author:HRL
*
* date:10/15/2020
* 
* description:
* 14、判断一棵二叉树是否为完全二叉树
* */


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

//先写一个非递归的层次遍历
Status func14(BiTree T)
{
	BiTree q[Max_num],  p = NULL;
	int front = 0, rear = 0,flag = 0;
	
	q[rear++] = T;
	p = T;
	while ( front < rear)
	{
		p = q[front++];
		if (NULL != p)
		{
			printf("%c ", p->data);
			//if (NULL != p->lchild)
				q[rear++] = p->lchild;
			//if (NULL != p->rchild)
				q[rear++] = p->rchild;
			if (flag == 1)
			{
				return false;
			}
			flag = 0;

		}
		if (NULL == p)
			flag = 1;
			
	}
	return true;
}

int main()
{
	//char string1[] = "AB##CD##E##";
	//char string1[] = "ABC##D##EF###";
	//char string1[] = "ABC##D###";
	//char string1[] = "AB#C#D##E##";
	char string[] = "AB##C##";
	
	//char string[] = "ABC##D##E#F##";
	//char string2[] = "ABC##D###";
	//char string[] = "AB#C#D##E##";
	//char string2[] = "AB##C##";

	BiTree T1  = NULL, T2 = NULL, T3 = NULL;
	int *id,start_id = 0;
	Status re = false;

	id = &start_id;

	T1 = CreatBiTree(string,id);

	
	visit_preorder(T1);
	puts("");	

	re = func14(T1);
	puts("");

	if (re)
		puts("是完全二叉树！");
	else
		puts("不是完全二叉树！");
	Tree2dot(T1);

	return 0;
}
