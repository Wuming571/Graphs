#include<stdio.h>
#include<stdlib.h>
//边集的数据
typedef struct ArcBox
{
	int tailvex, headvex;//弧尾、弧头所在的位置
	struct ArcBox* hlink;
	struct ArcBox* tlink;//弧尾相同、弧头相同的下一个弧
	int weight;
}ArcBox;
//顶点的数据
typedef struct VexNode
{
	int data;//真实的数据
	ArcBox* firstin, * firstout;//出度指针 入度指针
}VexNode;

typedef struct {
	VexNode xlist[20];
	int numV, numE;
}OLGraph;

void CreateDG(OLGraph* G)
{
	//输入顶点数和边数
	scanf_s("%d%d", &(G->numV), &(G->numE));
	for (int i = 0; i < G->numV; i++)
	{
		scanf_s("%d", &(G->xlist[i].data));
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}
	//构建十字链表
	for (int i = 0; i < G->numE; i++)
	{
		int v1, v2;
		scanf_s("%d%d", &v1, &v2);
		//查找相对应的下标
		ArcBox* p = (ArcBox*)malloc(sizeof(ArcBox));
		p->tailvex = v1;
		p->headvex = v2;
		//采用头插法插入新的p结点
		p->hlink = G->xlist[v2].firstin;
		p->tlink = G->xlist[v1].firstout;
		G->xlist[v2].firstin = G->xlist[v1].firstout = p;
	}
}

int main() {

	return 0;
}