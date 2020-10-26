/*
* author:HRL
*
* date:10/07/2020
* 
* description:
* 2、使用先序遍历和中序遍历方式建立一棵二叉树。
*/

#include <stdio.h>
#include "BiTree.h"
#include <stdlib.h>

BiTree func02(char *predef, char *middef, int pre_st, int pre_ed, int mid_st,int mid_ed)
{
	if (pre_st > pre_ed)
		return NULL;
	BiNode *t = NULL;
	//int id_root = st;
	t = (BiTree) malloc (sizeof(BiNode));
	t->data = predef[pre_st];
	t->lchild = NULL;
	t->rchild = NULL;

	int i;
	for (i = mid_st;i <= mid_ed; i++ )
		if (predef[pre_st] == middef[i])
		{
			break;
		}
	t->lchild = func02(predef,middef,pre_st + 1,pre_st + (i - mid_st) ,mid_st,i - 1);
	t->rchild = func02(predef,middef,pre_st + (i - mid_st) + 1,pre_ed, i + 1,mid_ed);
	//if ()
	return t;
}

int main()
{	
	char pre[] = "ABCDEF";	char mid[] = "BCAEDF";	int st = 0, ed = 5;
	//char pre[] = "ABC";	char mid[] = "BAC"; int st = 0, ed = 2;
	BiTree T = NULL;
	
	char *predef = pre, *middef = mid;
	T = func02(pre, mid ,st,ed,st, ed);

	visit_preorder(T);
	puts("");
	return 0;
}

