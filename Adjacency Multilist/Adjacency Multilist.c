#include<stdio.h>
//邻接多重表
//边表集合
typedef struct node
{
	int ivex, jvex;
	struct node* vi, * vj;
}ArcNode;
//结点
typedef struct
{
	char vertex;

	ArcNode* firstEdge;
}VNode;

typedef struct
{
	VNode Dvex[50];
	int numV, numE;
}Graph;

void creat(Graph* G)
{
	//先输入顶点数和边数
	scanf_s("%d%d", &(G->numV), &(G->numE));
	ArcNode* new_node;
	for (int i = 0; i < G->numV; i++)
	{
		scanf_s("%d", &G->Dvex[i].vertex);
		G->Dvex[i].firstEdge = NULL;
	}
	for (int i = 0; i < G->numE; i++)
	{
		//输入边对应的下标
		int vi, vj;
		scanf_s("%d%d", &vi, &vj);
		new_node = (ArcNode*)malloc(sizeof(ArcNode));
		new_node->ivex = vi;
		new_node->jvex = vj;
		new_node->vi = G->Dvex[vi].firstEdge;
		G->Dvex[vi].firstEdge = new_node;
		new_node->vj = G->Dvex[vj].firstEdge;
		G->Dvex[vj].firstEdge = new_node;
	}
}

int main() {

	return 0;
}