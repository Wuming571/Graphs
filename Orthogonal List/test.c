#include <stdio.h>
#include <stdlib.h>

//边集的数据
typedef struct ArcBox {
	int tailvex, headvex;//弧头弧尾所在的位置
	struct ArcBox* hlink;
	struct ArcBox* tlink;
	int weight;
}ArcBox;
//顶点数据，first指向边集数据
typedef struct VexNode {
	int data;//存储的数据
	ArcBox* firstin, * firstout;//出度指针 入度指针
}VexNode;
//代表整张图的一维数组，包含顶点数据
typedef struct {
	VexNode xlist[20];
	int numV, numE;
}OLGraph;

void CreateDG(OLGraph* G) {
	//输入顶点数和边数
	scanf_s("%d%d", &(G->numV), &(G->numE));
	//对结点进行初始化
	for (int i = 0; i < G->numV; i++) {
		scanf_s("%d", &(G->xlist[i].data));
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}
	//构建十字链表
	for (int i = 0; i < G->numE; i++) {
		//输入两个端点
		int v1, v2;
		scanf_s("%d%d", &v1, &v2);
		//构建两条链
		ArcBox* p = (ArcBox*)malloc(sizeof(ArcBox));
		p->tailvex = v1;
		p->tlink = G->xlist[v2].firstin;
		G->xlist[v2].firstin = p;

		p->headvex = v2;
		p->hlink = G->xlist[v2].firstout;
		G->xlist[v2].firstout = p;
	}
}
