#include <stdio.h>
#include <stdlib.h>

//�߼�������
typedef struct ArcBox {
	int tailvex, headvex;//��ͷ��β���ڵ�λ��
	struct ArcBox* hlink;
	struct ArcBox* tlink;
	int weight;
}ArcBox;
//�������ݣ�firstָ��߼�����
typedef struct VexNode {
	int data;//�洢������
	ArcBox* firstin, * firstout;//����ָ�� ���ָ��
}VexNode;
//��������ͼ��һά���飬������������
typedef struct {
	VexNode xlist[20];
	int numV, numE;
}OLGraph;

void CreateDG(OLGraph* G) {
	//���붥�����ͱ���
	scanf_s("%d%d", &(G->numV), &(G->numE));
	//�Խ����г�ʼ��
	for (int i = 0; i < G->numV; i++) {
		scanf_s("%d", &(G->xlist[i].data));
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}
	//����ʮ������
	for (int i = 0; i < G->numE; i++) {
		//���������˵�
		int v1, v2;
		scanf_s("%d%d", &v1, &v2);
		//����������
		ArcBox* p = (ArcBox*)malloc(sizeof(ArcBox));
		p->tailvex = v1;
		p->tlink = G->xlist[v2].firstin;
		G->xlist[v2].firstin = p;

		p->headvex = v2;
		p->hlink = G->xlist[v2].firstout;
		G->xlist[v2].firstout = p;
	}
}
