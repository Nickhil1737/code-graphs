#include<stdio.h>
#include<stdlib.h>

int V, E; 
int edgeIndx = 0;

struct edge{
    int u, v,w;
}* edges;

int d[10000], parent[1000];
void addEdge(int u, int v, int w){
    edges[edgeIndx].u = u;edges[edgeIndx].v = v;edges[edgeIndx++].w = w;
}

void relax(int u, int v, int w)
{
   if(d[v] > d[u] + w){
       d[v] = d[u] + w;
       parent[v] = u;
   } 
}
void initializeSS(int s)
{
    for(int i = 1; i < V+1; ++i){
        d[i] = 1e9;
        parent[i] = i;
    }
    d[s] = 0;
}

void bellmanford(int s)
{
    initializeSS(s);
    for(int j = 1;j < V; ++j){
        for(int i = 0; i < E; ++i){
            relax(edges[i].u,edges[i].v, edges[i].w);
        }
    }
    for(int i = 1; i < V+1; ++i){
        if(i == s)  continue;
        printf("%d %d \n",i, d[i]);
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

    bellmanford(1);

    return 0;
}

/*
Thursday 10 December 2020 09:03:19 PM IST
     author:   __astrainL3gi0N
*/
