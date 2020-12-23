#include<stdio.h>
#include<stdlib.h>

int V, E; 
int edgeIndx = 0;

struct edge{
    int u, v,w;
}* edges;

void addEdge(int u, int v, int w){
    edges[edgeIndx].u = u;edges[edgeIndx].v = v;edges[edgeIndx++].w = w;
}

int min(int x, int y)
{
    return x*(x<y) + y*(y<=x);
}

int fw[20][100][100];
void floydWarshall(int n)
{
    for(int i = 1; i < n+1; ++i)
        for(int j = 1; j < n+1; ++j)
            if(i == j)
                fw[0][i][j] = 0;
            else
                fw[0][i][j] = 1e6;
    for(int i = 0; i < E; ++i){
        int u,v,w;
        u = edges[i].u; v = edges[i].v; w = edges[i].w;
        fw[0][u][v] = w;
    }

    for(int k = 1; k < n+1; ++k){
        for(int i = 1; i < n+1; ++i){
            for(int j = 1; j < n+1; ++j){
                fw[k][i][j] = min(fw[k-1][i][j], fw[k-1][i][k]+fw[k-1][k][j]);
            }
        }
    }
    for(int i = 1; i < n+1; ++i){
        for(int j = 1; j < n+1; ++j)
            printf("%2d ",fw[n][i][j]);
            printf("\n");
    }

}

int main()
{
    scanf("%d %d",&V,&E);
    edges = (struct edge *) malloc(sizeof(struct edge)*E);

    for(int i = 0 ; i < E; ++i){
        int u,v,w;
        scanf("%d %d %d", &u,&v,&w);
        addEdge(u,v,w);
    }

    floydWarshall(V);

    return 0;
}

/*
Thursday 10 December 2020 09:03:19 PM IST
     author:   __astrainL3gi0N
*/
