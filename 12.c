/*
* author:HRL
*
* date:10/12/2020
* 
* description:
* 12、假设一个仅包含二元运算的算术表达式以二叉链表的形式存储在二叉树T里。
* 设计算法求表达式的值
* 注意：由于C语言用不了引用，而在写数据结构时可以用引用，所以12题只有cpp版本是可以跑通的！
*/


#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>
#include "output_demo.h"

//先写一个递归的后序遍历
void func12(BiTree T)
{
	if (NULL != T)
	{
		func12(T->lchild);
		func12(T->rchild);
		printf("%c ",T->data);
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

	func12(T1);
	puts("");
	Tree2dot(T1);

	return 0;
}
