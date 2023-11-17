#include <stdio.h>
#include <stdlib.h>
//�ڽӱ�

//�߱���
typedef struct EdgeNode {
	int adjvex;//�ڽӵĽ����±�
	struct EdgeNode* next;
	int weight;//Ȩֵ
}EdgeNode;
//�������Ϣ��ָ��߱���
typedef struct VertexNode {
	char data;//���������ݣ��������Ž����Ϣ
	struct EdgeNode* firstedge;
}VertexNode;
//�ڽӱ�ṹ����ͼ�����������Ϣ
typedef struct GraphadjList {
	VertexNode adjList[100];//�����Ľ������
	int numV, numE;//��������ͱߵĸ���
}GraphadjList;
//����ͼ���ڽӱ�Ĵ���
void CreatALGraph(GraphadjList* G) {
	int vi, vj;
	EdgeNode* e;
	////�����붥����Ϣ�ͱߵ���Ϣ
	//scanf_s("%d %d", &G->numV, &G->numE);
	////��ʼ�������Ϣ
	//for (int i = 0; i < G->numV; i++) {
	//	scanf_s("%c", &G->adjList[i].data);
	//	getchar();
	//	G->adjList[i].firstedge = NULL;
	//}

	G->numV = 4; // 4������
	G->numE = 4; // 4����

	char datas[] = { 'A', 'B', 'C', 'D' }; // ��������
	int edges[][2] = { {0, 1}, {0, 2}, {1, 2}, {2, 3} }; // �ߵ��������

	for (int i = 0; i < G->numV; i++)
	{
		G->adjList[i].data = datas[i];
		G->adjList[i].firstedge = NULL;
	}

	//�����߱�
	for (int i = 0; i < G->numE; i++) {
		////����ÿ�����ڽӵ���������
		//scanf_s("%d %d", &vi, &vj);
		vi = edges[i][0];
		vj = edges[i][1];
		//��������ľ��ǽ���λ�ã�����Ҫ�����±�
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = vj;//�ҵ�Ҫ������ϵ�����±�
		//����ͷ�巨����
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