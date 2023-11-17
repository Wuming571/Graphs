#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX 100

int visit[100];//标记的点是否被访问的数组
//带权无向图 邻接表
//边表数据结构
typedef struct EdgeNode {
	int adjvex;
	int weight;
	struct EdgeNode* next;
}EdgeNode;
//结点数据结构
typedef struct VertexNode {
	char Vertex;
	EdgeNode* FirstEdge;
}VertexNode;
//邻接链表图的数据结构
typedef struct {
	VertexNode adjList[100];
	int VeretexNumber, EdgeNumber;
}GraphAdjList;

//无向图邻接链表创建
void Create_no_direction_LinkList_Graph(GraphAdjList* G) {
	int i, w, k, j;
	scanf_s("%d%d", &G->VeretexNumber, &G->EdgeNumber);
	
	getchar();//关键性错误

	//对结点进行初始化
	for (i = 0; i < G->VeretexNumber; ++i) {
		scanf_s("%c", &G->adjList[i].Vertex);
		//将结点代表的数组初始化为空
		G->adjList[i].FirstEdge = NULL;
	}
	//对边进行初始化
	for (k = 0; k < G->EdgeNumber; ++k) {
		scanf_s("%d%d%d", &i, &j, &w);	//端点，权值
		EdgeNode* e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->weight = w;
		e->adjvex = j;
		e->next = G->adjList[i].FirstEdge;
		G->adjList[i].FirstEdge = e;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->weight = w;
		e->adjvex = i;
		e->next = G->adjList[j].FirstEdge;
		G->adjList[i].FirstEdge = e;
	}
}
//————————————————————————————————————————————
//创建队列，用来保存遍历的对象
typedef struct {
	char data[MAX_VERTEX];
	int front;
	int rear;
}SqQueue;
//队列初始化
void InitQueue(SqQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
}
//入队
bool EnQueue(SqQueue* Q, char e) {
	//判断队列是否满
	if ((Q->rear+1)%MAX_VERTEX == Q->front)
		return false;
	//队尾指针是否和队首指针重合
	Q->data[Q->rear] = e;
	//队尾指针后移
	Q->rear = (Q->rear + 1) % MAX_VERTEX;
	return true;
}
//出队 删除队首元素，并打印
char* DeQueue(SqQueue* Q, char* e) {
	//队列判空?
	if (Q->front == Q->rear)
		return NULL;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAX_VERTEX;
	return e;
}
//队列判空
bool isEmptyQueue(SqQueue* Q) {
	return Q->front == Q->rear ? true : false;
}
//——————————————————————————————————
//无向图邻接邻接链表广度优先遍历BFS
void BFS_Travel(GraphAdjList G) {
	int i,j,mark;
	char data;
	SqQueue Q;
	//初始化visit数组
	for (i = 0; i < G.VeretexNumber; i++)
		visit[i] = 0;
	//初始化队列
	InitQueue(&Q);
	//每个结点进行BFS
	for(i=0;i<G.VeretexNumber;++i){
		//检查图的结点是否访问过
		if (!visit[i]) {
			//重点，将队首结点出队，结点的邻接点入队
			visit[i] = true;
			EnQueue(&Q, G.adjList[i].Vertex);
			while (!isEmptyQueue(&Q)) {
				DeQueue(&Q, &data);
				printf("%c", data);
				//根据删除结点找到给节点下标，来找到它的邻接点
				//???
				for (j = 0; j < G.VeretexNumber; j++)
					if (G.adjList[j].Vertex == data)
						mark = j;
				//用p来暂存边表结点
				EdgeNode* p;
				p = G.adjList[mark].FirstEdge;
				//找到邻接点
				while (p) {
					if (!visit[p->adjvex]) {
						EnQueue(&Q,G.adjList[p->adjvex].Vertex);
						visit[p->adjvex] = true;
					}
					p = p->next;
				}
			}
		}
	}
}
int main() {
	GraphAdjList G;
	Create_no_direction_LinkList_Graph(&G);
	BFS_Travel(G);
	return 0;
}
