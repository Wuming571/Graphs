#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX 100

int visit[100];//��ǵĵ��Ƿ񱻷��ʵ�����
//��Ȩ����ͼ �ڽӱ�
//�߱����ݽṹ
typedef struct EdgeNode {
	int adjvex;
	int weight;
	struct EdgeNode* next;
}EdgeNode;
//������ݽṹ
typedef struct VertexNode {
	char Vertex;
	EdgeNode* FirstEdge;
}VertexNode;
//�ڽ�����ͼ�����ݽṹ
typedef struct {
	VertexNode adjList[100];
	int VeretexNumber, EdgeNumber;
}GraphAdjList;

//����ͼ�ڽ�������
void Create_no_direction_LinkList_Graph(GraphAdjList* G) {
	int i, w, k, j;
	scanf_s("%d%d", &G->VeretexNumber, &G->EdgeNumber);
	
	getchar();//�ؼ��Դ���

	//�Խ����г�ʼ��
	for (i = 0; i < G->VeretexNumber; ++i) {
		scanf_s("%c", &G->adjList[i].Vertex);
		//��������������ʼ��Ϊ��
		G->adjList[i].FirstEdge = NULL;
	}
	//�Ա߽��г�ʼ��
	for (k = 0; k < G->EdgeNumber; ++k) {
		scanf_s("%d%d%d", &i, &j, &w);	//�˵㣬Ȩֵ
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
//����������������������������������������������������������������������������������������
//�������У�������������Ķ���
typedef struct {
	char data[MAX_VERTEX];
	int front;
	int rear;
}SqQueue;
//���г�ʼ��
void InitQueue(SqQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
}
//���
bool EnQueue(SqQueue* Q, char e) {
	//�ж϶����Ƿ���
	if ((Q->rear+1)%MAX_VERTEX == Q->front)
		return false;
	//��βָ���Ƿ�Ͷ���ָ���غ�
	Q->data[Q->rear] = e;
	//��βָ�����
	Q->rear = (Q->rear + 1) % MAX_VERTEX;
	return true;
}
//���� ɾ������Ԫ�أ�����ӡ
char* DeQueue(SqQueue* Q, char* e) {
	//�����п�?
	if (Q->front == Q->rear)
		return NULL;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAX_VERTEX;
	return e;
}
//�����п�
bool isEmptyQueue(SqQueue* Q) {
	return Q->front == Q->rear ? true : false;
}
//��������������������������������������������������������������������
//����ͼ�ڽ��ڽ����������ȱ���BFS
void BFS_Travel(GraphAdjList G) {
	int i,j,mark;
	char data;
	SqQueue Q;
	//��ʼ��visit����
	for (i = 0; i < G.VeretexNumber; i++)
		visit[i] = 0;
	//��ʼ������
	InitQueue(&Q);
	//ÿ��������BFS
	for(i=0;i<G.VeretexNumber;++i){
		//���ͼ�Ľ���Ƿ���ʹ�
		if (!visit[i]) {
			//�ص㣬�����׽����ӣ������ڽӵ����
			visit[i] = true;
			EnQueue(&Q, G.adjList[i].Vertex);
			while (!isEmptyQueue(&Q)) {
				DeQueue(&Q, &data);
				printf("%c", data);
				//����ɾ������ҵ����ڵ��±꣬���ҵ������ڽӵ�
				//???
				for (j = 0; j < G.VeretexNumber; j++)
					if (G.adjList[j].Vertex == data)
						mark = j;
				//��p���ݴ�߱���
				EdgeNode* p;
				p = G.adjList[mark].FirstEdge;
				//�ҵ��ڽӵ�
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
