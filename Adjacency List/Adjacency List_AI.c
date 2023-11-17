#include<stdio.h>
#include<stdlib.h>

typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode
{
	char data;
	struct EdgeNode* firstedge;
}VertexNode;

typedef struct GraphadjList
{
	VertexNode adjList[100];
	int numV, numE;
}GraphadjList;

void CreatALGraph(GraphadjList* G)
{
	int vi, vj;
	EdgeNode* e;

	G->numV = 4; // 4个顶点
	G->numE = 4; // 4条边

	char datas[] = { 'A', 'B', 'C', 'D' }; // 顶点数据
	int edges[][2] = { {0, 1}, {0, 2}, {1, 2}, {2, 3} }; // 边的连接情况

	for (int i = 0; i < G->numV; i++)
	{
		G->adjList[i].data = datas[i];
		G->adjList[i].firstedge = NULL;
	}

	for (int i = 0; i < G->numE; i++)
	{
		vi = edges[i][0];
		vj = edges[i][1];

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = vj;
		e->next = G->adjList[vi].firstedge;
		G->adjList[vi].firstedge = e;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = vi;
		e->next = G->adjList[vj].firstedge;
		G->adjList[vj].firstedge = e;
	}
}

void PrintGraph(GraphadjList* G)
{
	for (int i = 0; i < G->numV; i++)
	{
		printf("%c: ", G->adjList[i].data);
		EdgeNode* e = G->adjList[i].firstedge;
		while (e != NULL)
		{
			printf("%c ", G->adjList[e->adjvex].data);
			e = e->next;
		}
		printf("\n");
	}
}

int main()
{
	GraphadjList G;
	CreatALGraph(&G);
	PrintGraph(&G);
	return 0;
}
