#include <stdio.h>
#include <stdlib.h>

//边集的数据
typedef struct ArcBox {
	int tailvex,headvex;
	struct ArcBox* hlink, * tlink;
	int weight;
}ArcBox;
//顶点数据，first指向边集数据
typedef struct VexNode {
	int data;
	ArcBox* firstin, * firstout;
}VexNode;
//代表整张图的一维数组，包含顶点数据
typedef struct {
	VexNode xlist[20];
	int numV, numE;
}OLGraph;

void CreateDG(OLGraph* G) {
	////输入顶点数和边数
	//scanf_s("%d%d", &(G->numE), &(G->numV));
	//对结点进行初始化	
	G->numV = 4;
	G->numE = 4;
	int vertexData[] = { 1, 2, 3, 4 };
	int edgeData[][2] = { {1, 2}, {2, 3}, {3, 4}, {4, 1} };

	for (int i = 0; i < G->numV; i++) {
		//scanf_s("%d", &G->xlist[i]->data);
		G->xlist[i].data = vertexData[i];
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}

	//构建十字链表
	for (int i = 0; i < G->numE; i++) {
		ArcBox* p = (ArcBox*)malloc(sizeof(ArcBox));
		int vi, vj;
		////输入两个端点
		//scanf_s("%d%d", &vi, &vj);
		printf("%d\n", i);
		vi = edgeData[i][0]-1;
		vj = edgeData[i][1]-1;
		//构建两条链
		p->tailvex = vi;
		p->tlink = G->xlist[vi].firstin;
		G->xlist[vi].firstin = p;

		p->headvex = vj;
		p->hlink = G->xlist[vj].firstout;
		G->xlist[vj].firstout = p;
	}
}

void PrintGraph(OLGraph* G)
{
	for (int i = 0; i < G->numV; i++)
	{
		printf("Vertex %d:\n", G->xlist[i].data);
		ArcBox* p = G->xlist[i].firstout;
		while (p != NULL)
		{
			printf("Edge from %d to %d\n", p->tailvex + 1, p->headvex + 1);
			p = p->tlink;
		}
		printf("\n");
	}
}


int main() {
	OLGraph* G = (OLGraph*)malloc(sizeof(OLGraph));
	CreateDG(G);
	PrintGraph(G);
	return 0;
}