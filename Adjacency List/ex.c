#include <stdio.h>
#include <stdlib.h>
//�ڽӱ�

//�߱���
typedef struct EdgeNode {
	int adjvex;//�ڽӵĽ����±�
	struct EdgeNode* next;//ָ����һ����
	int weight;//Ȩֵ
}EdgeNode;
//�������Ϣ��ָ��߱���
typedef struct VertexNode {
	char data;//���������ݣ��������Ž����Ϣ
	struct EdgeNode* first;
}VertexNode;
//�ڽӱ�ṹ����ͼ�����������Ϣ
typedef struct GraphadjList {
	VertexNode adjList[100];//�����Ľ������
	int numV, numE;//��������ͱߵĸ���
}GraphadjList;
//����ͼ���ڽӱ�Ĵ���
void CreatALGraph(GraphadjList* G) {

	G->numV = 4; // 4������
	G->numE = 4; // 4����

	char datas[] = { 'A', 'B', 'C', 'D' }; // ��������
	int edges[][2] = { {0, 1}, {0, 2}, {1, 2}, {2, 3} }; // �ߵ��������

	EdgeNode* e;
	int vi, vj;

	//�����߱�
	for (int i = 0; i < G->numE; i++) {
		G->adjList[i].data = datas[i];
		G->adjList[i].first = NULL;
	}
	for (int i = 0; i < G->numV; i++) {
		//��������ľ��ǽ���λ�ã�����Ҫ�����±�
		vi = edges[i][0];
		vj = edges[i][1];
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = vj;
		//�ҵ�Ҫ������ϵ�����±�		
		//����ͷ�巨����
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

//����forѭ����i<= <������
//�����Ȳ�˭���˭������