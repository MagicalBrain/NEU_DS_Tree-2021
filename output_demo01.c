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

//先写一个非递归的层次遍历
char* level_order(BiTree T)
{
	BiTree q[Max_num],  p = NULL;
	char data[50] = "";
	char *re = data;
	int front = 0, rear = 0, top = 0;
	
	q[rear++] = T;
	p = T;
	while ( front < rear)
	{
		p = q[front++];
		if (NULL != p)
		{
			printf("%d - %c ", top,p->data);
			re[top++] = p->data;
			//if (NULL != p->lchild)
				q[rear++] = p->lchild;
			//if (NULL != p->rchild)
				q[rear++] = p->rchild;
		}
		else
			re[top++] = '#';
		printf("level_order top:%d %c\n",top,re[top-1]);

	}
	re[top] = '\0';
		return re;
}

void Tree2dot01(char *data,FILE *Tree)
{
	int top = 0;
	puts("data:");
	puts(data);
	while (data[top] != '\0')
	{
		if (data[top] != '#')
		{
			fprintf(Tree,"node%d[label = \"%c\"];\n",top,data[top]);
			printf("Tree2dot 01 %d:%c\n",top,data[top]);
		if (data[top*2+1] != '#')
			fprintf(Tree,"node%d -> node%d;\n",top,top*2+1);
		if (data[top*2+2] != '#')
			fprintf(Tree,"node%d -> node%d;\n",top,top*2+2);
		}
		top++;

	}
	printf("Tree2dot0  top:%d\n",top);

}



void Tree2dot_main(BiTree T)
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

void Tree2dot_main01(BiTree T)
{
	if (NULL == T)
		return;

	char str01[50] = "";
	char str02[] = "/home/Tree_PNG/";
	char *filename = str01, *basefilename = str02, *data = NULL;
	
	int top = 0;

	puts("请输入dot文件名：");
	gets(filename);
	FILE *Tree;
	
	filename = strcat(basefilename,filename);
	printf("当前dot文件输出路径为：%s\n", filename);
	Tree = fopen(filename,"w");

	data = level_order(T);
	puts("");

	puts("data:");
	puts(data);

	printf("data's length:%d\n",strlen(data));
	while (data[top] != '\0' && top < 9)
		printf("%c ",data[top++]);
	puts("");

	fprintf(Tree,"digraph {\n");

	//fprintf(Tree,"A -> B;\n");
	Tree2dot01(data,Tree);

	fprintf(Tree,"}\n");
	fclose(Tree);
}

int main()
{
	char string[] = "AB#B##C##";
	char *defbit = string;

	int i = 0;
	int *id = &i;
	BiTree T = (BiTree) malloc (sizeof(BiNode));
		
	T = CreatBiTree( defbit, id);

	visit_preorder(T);
	puts("");
	
	Tree2dot_main01(T);
	return 0;
}

