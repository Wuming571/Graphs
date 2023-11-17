/*
创建无权无向图并深度优先搜索--基于邻接矩阵存图
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
typedef struct ArcCell {
    char vexnum[MAXN];         //顶点
    int arcnum[MAXN][MAXN];    //弧
    int n, e;                  //顶点数， 弧数
}Graph;
int Visit[MAXN];         //定义Visit来判断顶点是否被访问，并初始化（全局变量默认为0） 

void CreateGraph(Graph* G) {        //创建图 ，此处注意&G 
    int s, t;
    scanf_s("%d %d", &G->n, &G->e);
    getchar();//读掉回车 
    for (int i = 0; i < G->n; i++) {
        scanf_s("%c", &G->vexnum[i]);

    }
    for (int i = 0; i < G->n; i++) {              //初始化数据 
        for (int j = 0; j < G->n; j++) {
            G->arcnum[i][j] = 0;
        }
    }
    for (int i = 0; i < G->e; i++) {              //创建图的邻接矩阵
        scanf_s("%d %d", &s, &t);
        G->arcnum[s][t] = 1;
        G->arcnum[t][s] = 1;
    }
}

//开始搜索 找一个开始结点
/*
开始结点是人定义的
Graph G 需要遍历哪一个图
int i 遍历的起始结点从哪里开始
标记结点
1、遍历未被标记的结点
2、如果遍历到某一个邻接点是已被标记 我要继续找和我相邻的另外一个结点

*/
void DFSTraverse(Graph G, int i)//找邻接点
{
    printf("%c", G.vexnum[i]);

    for (int j = 0; j < G.n; j++)
    {
        if (G.arcnum[i][j] && !Visit[j])
        {
            Visit[j] = 1;
            DFSTraverse(G, j);
        }

    }

}

void DFS(Graph G)//遍历
{
    for (int i = 0; i < G.n; i++)//对整个图的结点进行深搜
    {
        if (!Visit[i])
        {
            Visit[i] = 1;
            DFSTraverse(G, i);
        }
    }
}

int main()
{
    Graph G;
    CreateGraph(&G);
    DFS(G);
    return 0;

}
/*
测试用例：
9
15
ABCDEFGHI
0 1
0 5
1 6
5 6
2 1
1 8
2 8
6 7
2 3
3 8
3 7
3 4
4 7
4 5
3 6
*/
