//������Ȩ����ͼ�� ����������� �������� �ڽӾ��� ��ͼ

#include <stdio.h>
#include <stdlib.h>
#define MAXN 100

typedef struct ArcCell {
	char vexnum[MAXN];//����
	int arcnum[MAXN][MAXN];//��ά������
	int n, e;//������������
}Graph;

int Visit[MAXN];//����Visit���ж϶����Ƿ񱻷��ʣ�����ʼ����Ĭ��Ϊ0��

void CreateGraph(Graph* G) {
	int s, t;
	scanf_s("%d%d", &G->n, &G->e);
	getchar();//�����س�
	//������ĸ���
	for (int i = 0; i < G->n; i++) {
		scanf_s("%c", &G->vexnum[i]);
	}
	//��ʼ����ά����
	for (int i = 0; i < G->n; i++) {
		for (int j = 0; j < G->n; j++) {
			G->arcnum[i][j] = 0;
		}
	}
	//����ߵ���Ϣ�������ڽӾ���
	for (int i = 0; i < G->e; i++) {
		scanf_s("%d%d", &s, &t);
		G->arcnum[s][t] = 1;
		G->arcnum[t][s] = 1;
	}
}

//��ʼ���� �ҵ�һ����ʼ���
/*
* ��ʼ���ʱ�˶����
* Graph G ��Ҫ������һ��ͼ
* int i ������ʼ�յ�����￪ʼ
* ��ǽ��
* 1������δ����ǵĽ��
* 2�����������ĳһ���ڽӵ����ѱ���� ��Ҫ�����Һ������ڵ�����һ�����
*/

void DFSTraverse(Graph G, int i) {//�ҵ��ڽӵ�
	printf("%c", G.vexnum[i]);
	//�Ըýڵ���ڽӵ��������
	for (int j = 0; j < G.n; j++) {
		if (G.arcnum[i][j] && !Visit[j]) {
			Visit[j] = 1;
			DFSTraverse(G, j);
		}
	}
}

void DFS(Graph G) {//����
	//������ͼ�Ľ����������������ֹ����ͼ���ж����ͨ����
	for (int i = 0; i < G.n; i++) {
		if (!Visit[i]) {
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