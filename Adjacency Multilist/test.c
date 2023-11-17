#include <stdio.h>
#include <stdlib.h>
//邻接多重表
//边表集合
typedef struct node {
	int ivex, jvex;
	struct node* vi, * vj;
}ArcNode;
//结点
typedef struct {
	char vertex;
	ArcNode* firstEdge;
}VNode;

typedef struct {
	VNode Dvex[50];
	int numV, numE;
}Graph;

void creat(Graph* G) {
	//先输入结点
	scanf_s("%d", &G->numV);
	for (int i = 0; i < G->numV; ++i) {
		scanf_s("%d", &G->Dvex[i].vertex);
		G->Dvex[i].firstEdge = NULL;
	}
	scanf_s("%d", &G->numE);
	for (int i = 0; i < G->numE; ++i) {
		int vi, vj;
		scanf_s("%d%d", &vi, &vj);
		ArcNode* e = (ArcNode*)malloc(sizeof(ArcNode));
		e->vi = vi;
		e->vj = vj;
		e->ivex = G->Dvex[vi].firstEdge;
		G->Dvex[vi].firstEdge = e;

		e->jvex = G->Dvex[vj].firstEdge;
		G->Dvex[vj].firstEdge = e;
	}
}

int main() {
	Graph G;
	creat(&G);
	return 0;
}

/*
输入样例：
5
1 2 3 4 5
4
0 1
1 2
2 3
3 4
*/
