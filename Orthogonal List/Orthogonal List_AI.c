#include <stdio.h>
#include <stdlib.h>

typedef struct ArcBox
{
	int tailvex, headvex;
	struct ArcBox* hlink, * tlink;
	int weight;
} ArcBox;

typedef struct VexNode
{
	int data;
	ArcBox* firstin, * firstout;
} VexNode;

typedef struct
{
	VexNode xlist[20];
	int numV, numE;
} OLGraph;

void CreateDG(OLGraph* G)
{
	G->numV = 4;
	G->numE = 4;
	int vertexData[4] = { 1, 2, 3, 4 };
	int edgeData[4][2] = { {1, 2}, {2, 3}, {3, 4}, {4, 1} };

	for (int i = 0; i < G->numV; i++)
	{
		G->xlist[i].data = vertexData[i];
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}
	for (int i = 0; i < G->numE; i++)
	{
		int v1 = edgeData[i][0] - 1;
		int v2 = edgeData[i][1] - 1;
		ArcBox* p = (ArcBox*)malloc(sizeof(ArcBox));
		p->tailvex = v1;
		p->headvex = v2;
		p->hlink = G->xlist[v2].firstin;
		p->tlink = G->xlist[v1].firstout;
		G->xlist[v2].firstin = G->xlist[v1].firstout = p;
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

int main()
{
	OLGraph G;
	CreateDG(&G);
	PrintGraph(&G);
	return 0;
}
