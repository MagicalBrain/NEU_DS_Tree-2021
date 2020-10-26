#include <stdio.h>
#include <string.h>
#include "BiTree.h"

void Tree2dot0(BiTree T,FILE *Tree)
{
	if (NULL != T)
	{
		fprintf(Tree,"%c;\n",T->data);

		if (NULL != T->lchild)
			fprintf(Tree,"%c -> %c;\n",T->data,T->lchild->data);
		if (NULL != T->rchild)
			fprintf(Tree,"%c -> %c;\n",T->data,T->rchild->data);
		
		Tree2dot0(T->lchild,Tree);
		Tree2dot0(T->rchild,Tree);
	}
}

void Tree2dot(BiTree T)
{
	if (NULL == T)
		return;

	char str01[50] = "";
	char str02[] = "/home/Tree_PNG/";
	char *filename = str01, *basefilename = str02;
	puts("请输入dot文件名：");
	gets(filename);
	FILE *Tree;
	
	filename = strcat(basefilename,filename);
	printf("当前dot文件输出路径为：%s\n", filename);
	Tree = fopen(filename,"w");

	fprintf(Tree,"digraph {\n");

	//fprintf(Tree,"A -> B;\n");
	Tree2dot0(T,Tree);
	fprintf(Tree,"}\n");
	fclose(Tree);
}


