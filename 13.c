/*
* author:HRL
*
* date:10/13/2020
* 
* description:
* 13、二叉树的层次遍历
* */


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

//先写一个递归的层次遍历
void func13(BiTree T)
{
	BiTree q[Max_num],  p = NULL;
	int front = 0, rear = 0;
	
	q[rear++] = T;
	p = T;
	while (p != NULL && front < rear)
	{
		p = q[front++];
		if (NULL != p)
		{
			printf("%c ", p->data);
			if (NULL != p->lchild)
				q[rear++] = p->lchild;
			if (NULL != p->rchild)
				q[rear++] = p->rchild;
		}
	}

}

int main()
{
	//char string1[] = "AB##CD##E##";
	//char string1[] = "ABC##D##EF###";
	//char string1[] = "ABC##D###";
	//char string1[] = "AB#C#D##E##";
	//char string1[] = "AB##C##";
	
	char string[] = "ABC##D##EF###";
	//char string2[] = "ABC##D###";
	//char string2[] = "AB#C#D##E##";
	//char string2[] = "AB##C##";

	BiTree T1  = NULL, T2 = NULL, T3 = NULL;
	int *id,start_id = 0;
	id = &start_id;

	T1 = CreatBiTree(string,id);

	
	visit_preorder(T1);
	puts("");	

	func13(T1);
	puts("");
	Tree2dot(T1);

	return 0;
}
