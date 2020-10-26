/*
* author:HRL
*
* date:10/15/2020
* 
* description:
* 15、求二叉树的最大宽度
* */


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

//先写一个非递归的层次遍历
int func15(BiTree T)
{
	BiTree q[Max_num],  p = NULL, flag = NULL;
	int front = 0, rear = 0, re = 1,num = 0, last = 1;
	
	if (NULL == T)
		return 0;

	q[rear++] = T;
	p = T;
	flag = p->lchild;
	while (p != NULL && front < rear)
	{
		p = q[front++];
		num++;
		if (NULL == p)
			break;
		if (NULL != p->lchild)
			q[rear++] = p->lchild;
		if (NULL != p->rchild)
			q[rear++] = p->rchild;
		if (last == front)
		{
			if (num > re)
				re = num;
			last = rear;
			num = 0;
		}
	}
	return re;
}

int main()
{
	//char string1[] = "AB##CD##E##";
	//char string1[] = "ABC##D##EF###";
	//char string1[] = "ABC##D###";
	//char string1[] = "AB#C#D##E##";
	//char string1[] = "AB##C##";
	
	//char string[] = "ABC##D##EF###";
	char string[] = "ABC##D###";
	//char string2[] = "AB#C#D##E##";
	//char string2[] = "AB##C##";

	BiTree T1  = NULL, T2 = NULL, T3 = NULL;
	int *id,start_id = 0, re = 0;
	id = &start_id;

	T1 = CreatBiTree(string,id);

	
	visit_preorder(T1);
	puts("");	

	re = func15(T1);
	printf("result:%d\n",re);

	Tree2dot(T1);

	return 0;
}
