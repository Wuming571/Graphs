#include <stdio.h>
#include <stdlib.h>

//һ��һά��������㼯��
//һ����ά�������߼���
#define MaxVertices 100
#define MaxWeight 32767//��Ȩͼ ���ڽӵĵ� Ȩֵ�����16λint��Χ-32768����+32767��
typedef struct {
	int Vertices[MaxVertices];//���������
	int Edge[MaxVertices][MaxVertices];//�ߵ���Ϣ
	int numV;//����ĸ���
	int numE;//�ߵĸ���
}AdjMatrix;

int n, e;
int vi, vj, w;


void CreateGraph(AdjMatrix* G) {
	//������ͼ�Ķ�������ͱߵĸ���
	printf("����ͼ�Ķ�������ͱߵĸ���");
	scanf_s("%d %d", &n, &e);
	G->numV = n;
	G->numE = e;

	//���г�ʼ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				G->Edge[i][j] = 0;//�Խ��߷�0
			else
				G->Edge[i][j] = MaxWeight;//��ʼ��Ϊ�����
		}
	}
	//����ߵ���Ϣ
	printf("����ߵ���Ϣ");
	for (int i = 0; i < G->numV; i++)
		scanf_s("%d", &G->Vertices[i]);
	printf("�����Ӧ���ߣ��Լ�����Ȩֵ");
	for (int i = 0; i < G->numE; i++) {
		scanf_s("%d %d %d", &vi, &vj, &w);
		//�ҵ���Ӧ���±�
		G->Edge[vi][vj] = w;
		//����ͼ�ǶԳƵľ���
		G->Edge[vj][vi] = w;
	}
}

void ShowAdj(AdjMatrix* G) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("���Ϊ%d\n", G->Vertices[i]);
			printf("<i> <j>�ߵ�ȨֵΪ%d\n", G->Edge[i][j]);
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