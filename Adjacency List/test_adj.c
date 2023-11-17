#include <stdio.h>
#include <stdlib.h>
//邻接表

//边表结点
typedef struct EdgeNode {
	int adjvex;//邻接的结点的下标
	struct EdgeNode* next;
	int weight;//权值
}EdgeNode;
//顶点的信息，指向边表结点
typedef struct VertexNode {
	char data;//基本的数据，顶点域存放结点信息
	struct EdgeNode* firstedge;
}VertexNode;
//邻接表结构，存图包含顶点的信息
typedef struct GraphadjList {
	VertexNode adjList[100];//顶点表的结点数组
	int numV, numE;//顶点个数和边的个数
}GraphadjList;
//无向图的邻接表的创建
void CreatALGraph(GraphadjList* G) {
	int vi, vj;
	EdgeNode* e;
	////先输入顶点信息和边的信息
	//scanf_s("%d %d", &G->numV, &G->numE);
	////初始化结点信息
	//for (int i = 0; i < G->numV; i++) {
	//	scanf_s("%c", &G->adjList[i].data);
	//	getchar();
	//	G->adjList[i].firstedge = NULL;
	//}

	G->numV = 4; // 4个顶点
	G->numE = 4; // 4条边

	char datas[] = { 'A', 'B', 'C', 'D' }; // 顶点数据
	int edges[][2] = { {0, 1}, {0, 2}, {1, 2}, {2, 3} }; // 边的连接情况

	for (int i = 0; i < G->numV; i++)
	{
		G->adjList[i].data = datas[i];
		G->adjList[i].firstedge = NULL;
	}

	//建立边表
	for (int i = 0; i < G->numE; i++) {
		////输入每条边邻接的两个顶点
		//scanf_s("%d %d", &vi, &vj);
		vi = edges[i][0];
		vj = edges[i][1];
		//这里输入的就是结点的位置，不需要在找下标
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = vj;//找到要建立关系结点的下表
		//进行头插法插入
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

int main() {
	GraphadjList* G;
	G = (GraphadjList*)malloc(sizeof(GraphadjList));
	CreatALGraph(G);
	PrintGraph(G);

	return 0;
}