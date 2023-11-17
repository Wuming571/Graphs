#include <stdio.h>

//一个数组代表顶点集合
//一个二维数组来代表边集
#define MaxVertices 100
#define MaxWeight 32767 //带权图 点不邻接的时候 无穷大（16位int范围-32768~+32767） 
typedef struct {
	int Vertices[MaxVertices];//顶点的数组信息
	int Edge[MaxVertices][MaxVertices];//边的信息
	int numV;//顶点的个数
	int numE;//边的个数
}AdjMatrix;

void CreateGraph(AdjMatrix* G)
{
	int n, e;
	int vi, vj, w;
	//先输入图的顶点的个数和边的个数
	scanf_s("%d,%d", &n, &e);
	G->numV = n; G->numE = e;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G->Edge[i][j] = 0;
			}
			else
			{
				G->Edge[i][j] = MaxWeight;
			}
		}
	}
	//把顶点放到数组当中
	for (int i = 0; i < G->numV; i++)
	{
		//开始输入顶点的信息
		scanf_s("%d", &G->Vertices[i]);
	}

	//输入边的信息
	for (int i = 0; i < G->numE; i++)
	{
		//输入边的信息 邻接点的两端 如果是带权图 输入边的权值
		scanf_s("%d%d%d", &vi, &vj, &w);
		//还要在查找 找到对应的下标
		G->Edge[vi][vj] = w;
		//如果是无向图 是个对称矩阵
		G->Edge[vj][vi] = w;
	}


}

int main() {
	return 0;
}