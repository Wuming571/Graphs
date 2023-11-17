#include<stdio.h>
#include<stdlib.h>

//邻接表
//边表结点
typedef struct EdgeNode
{
	int adjvex;//邻接的结点的下标

	struct EdgeNode* next;

	int weight;//如果是个带权图 要有权值
}EdgeNode;
//z顶点信息
typedef struct VertexNode
{
	char data;//基本的数据 顶点域存放顶点信息
	struct EdgeNode* firstedge;
}VertexNode;
//邻接表的结构
typedef struct GraphadjList
{
	VertexNode adjList[100];//顶点表的结点数组
	int numV, numE;//顶点个数和边的个数
}GraphadjList;
//无向图的邻接表的创建
void CreatALGraph(GraphadjList* G)
{
	int vi, vj;
	EdgeNode* e;
	//先输入顶点信息和边的信息
	scanf_s("%d%d", &G->numV, &G->numE);
	//初始化结点信息
	for (int i = 0; i < G->numV; i++)
	{
		scanf_s("%c", &G->adjList[i].data);
		getchar();
		G->adjList[i].firstedge = NULL;
	}
	//建立边表
	for (int i = 0; i < G->numE; i++)
	{
		//输入每条边邻接的两个顶点
		scanf_s("%d%d", &vi, &vj);
		//如果输入的是真实的数据 还是要去找下标
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

int main() {

	return 0;
}
