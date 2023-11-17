//创建无权无向图并 深度优先搜索 ——基于 邻接矩阵 存图

#include <stdio.h>
#include <stdlib.h>
#define MAXN 100

typedef struct ArcCell {
	char vexnum[MAXN];//顶点
	int arcnum[MAXN][MAXN];//二维数组存边
	int n, e;//顶点数，边数
}Graph;

int Visit[MAXN];//定义Visit来判断顶点是否被访问，并初始化（默认为0）

void CreateGraph(Graph* G) {
	scanf_s("%d%d", &G->n, &G->e);
	getchar();//读掉回车
	//输入结点的个数
	for (int i = 0; i < G->n; i++) {
		scanf_s("%c", &G->vexnum[i]);

	}
	//初始化二维数组
	for (int i = 0; i < G->n; i++) {
		for (int j = 0; j < G->n; j++) {
			G->arcnum[i][j] = 0;
		}
	}
	//输入边的信息，创建邻接矩阵
	int vi, vj;

	for (int i = 0; i < G->e; i++) {
		scanf_s("%d%d", &vi, &vj);
		G->arcnum[vi][vj] = 1;
		G->arcnum[vj][vi] = 1;
	}
}

//开始搜索 找到一个开始结点
/*
* 开始结点时人定义的
* Graph G 需要遍历哪一个图
* int i 遍历起始终点从哪里开始
* 标记结点
* 1、遍历未被标记的结点
* 2、如果遍历到某一个邻接点是已被标记 我要继续找和我相邻的另外一个结点
*/

void DFSTraverse(Graph G, int i) {//找到邻接点
	printf("%c", G.vexnum[i]);
	//对该节点的邻接点进行搜索
	for (int j = 0; j < G.n; j++) {
		if (Visit[j] == 0 && G.arcnum[i][j]) {
			Visit[j] = 1;
			DFSTraverse(G, j);
		}
	}
}

void DFS(Graph G) {//遍历
	//对整个图的结点进行深度搜索，防止出现图含有多个连通分量
	for (int i = 0; i < G.n; i++) {
		if (Visit[i] == 0) {
			Visit[i] = 1;
			DFSTraverse(G, i);
		}
	}
}

int main() {
	Graph G;
	CreateGraph(&G);
	DFS(G);
	return 0;
}