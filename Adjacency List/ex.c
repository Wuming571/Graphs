#include <stdio.h>
#include <stdlib.h>
//邻接表

//边表结点
typedef struct EdgeNode {
	int adjvex;//邻接的结点的下标
	struct EdgeNode* next;//指向下一个边
	int weight;//权值
}EdgeNode;
//顶点的信息，指向边表结点
typedef struct VertexNode {
	char data;//基本的数据，顶点域存放结点信息
	struct EdgeNode* first;
}VertexNode;
//邻接表结构，存图包含顶点的信息
typedef struct GraphadjList {
	VertexNode adjList[100];//顶点表的结点数组
	int numV, numE;//顶点个数和边的个数
}GraphadjList;
//无向图的邻接表的创建
void CreatALGraph(GraphadjList* G) {

	G->numV = 4; // 4个顶点
	G->numE = 4; // 4条边

	char datas[] = { 'A', 'B', 'C', 'D' }; // 顶点数据
	int edges[][2] = { {0, 1}, {0, 2}, {1, 2}, {2, 3} }; // 边的连接情况

	EdgeNode* e;
	int vi, vj;

	//建立边表
	for (int i = 0; i < G->numE; i++) {
		G->adjList[i].data = datas[i];
		G->adjList[i].first = NULL;
	}
	for (int i = 0; i < G->numV; i++) {
		//这里输入的就是结点的位置，不需要在找下标
		vi = edges[i][0];
		vj = edges[i][1];
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = vj;
		//找到要建立关系结点的下表		
		//进行头插法插入
		e->next = G->adjList[vi].first;
		G->adjList[vi].first = e;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = vi;
		e->next = G->adjList[vj].first;
		G->adjList[vj].first = e;
	}
}

void PrintGraph(GraphadjList* G)
{
	for (int i = 0; i < G->numV; i++)
	{
		printf("%c: ", G->adjList[i].data);
		EdgeNode* e = G->adjList[i].first;
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

//关于for循环是i<= <的问题
//关于先插谁后插谁的问题