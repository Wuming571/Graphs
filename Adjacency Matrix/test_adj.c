#include <stdio.h>
#include <stdlib.h>

//一个一维数组代表顶点集合
//一个二维数组代表边集合
#define MaxVertices 100
#define MaxWeight 32767//带权图 不邻接的点 权值无穷大（16位int范围-32768——+32767）
typedef struct {
	int Vertices[MaxVertices];//顶点的数组
	int Edge[MaxVertices][MaxVertices];//边的信息
	int numV;//顶点的个数
	int numE;//边的个数
}AdjMatrix;

int n, e;
int vi, vj, w;


void CreateGraph(AdjMatrix* G) {
	//先输入图的顶点个数和边的个数
	printf("输入图的顶点个数和边的个数");
	scanf_s("%d %d", &n, &e);
	G->numV = n;
	G->numE = e;

	//进行初始化
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				G->Edge[i][j] = 0;//对角线放0
			else
				G->Edge[i][j] = MaxWeight;//初始化为无穷大
		}
	}
	//输入边的信息
	printf("输入边的信息");
	for (int i = 0; i < G->numV; i++)
		scanf_s("%d", &G->Vertices[i]);
	printf("输入对应两边，以及它的权值");
	for (int i = 0; i < G->numE; i++) {
		scanf_s("%d %d %d", &vi, &vj, &w);
		//找到对应的下标
		G->Edge[vi][vj] = w;
		//无向图是对称的矩阵
		G->Edge[vj][vi] = w;
	}
}

void ShowAdj(AdjMatrix* G) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("结点为%d\n", G->Vertices[i]);
			printf("<i> <j>边的权值为%d\n", G->Edge[i][j]);
		}
	}
}

int main() {
	AdjMatrix* G;
	G = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	memset(G, 0, sizeof(AdjMatrix));
	CreateGraph(G);

	ShowAdj(G);
	return 0;
}