#include<stdio.h>
#include<stdlib.h>

int V, E; 
int kindx;
int edgeIndx = 0;

struct edge{
    int u, v,w;
}* edges, *kedges[1000];

void addEdge(int u, int v, int w){
    edges[edgeIndx].u = u;edges[edgeIndx].v = v;edges[edgeIndx++].w = w;
}

int ufrank[1000],parent[10000];
void make_set(int x)
{
    parent[x] = x;
    ufrank[x] = 0;
}
int find_set(int x)
{
    while(x != parent[x])
        x = parent[x];
    return x;
}
void link(int x,int y)
{
    if(ufrank[x] > ufrank[y])
        parent[y] = x;
    else{
        parent[x] = y;
        if(ufrank[x] == ufrank[y])
            ufrank[y] = 1+ ufrank[y];
    }
}
void unionf(int x, int y)
{
    link(find_set(x),find_set(y));
}

int comparator(const void *p , const void *q)
{
    int l = ((struct edge *)p)->w;
    int r = ((struct edge *)q)->w;
    return l-r;
}

void mstkruskal()
{
    for(int i = 1; i < V+1; ++i)
        make_set(i);
    qsort((void *)edges, E, sizeof(struct edge), comparator);
    int sum = 0;
    kindx = 0;
    for(int i = 0 ; i < E; ++i){
        if(find_set(edges[i].u) != find_set(edges[i].v)){
            unionf(edges[i].u, edges[i].v);
            kedges[kindx++] = edges+i;
            sum += edges[i].w;

        }
    }
    printf(" % d\n" , sum);
    for(int i = 0; i < kindx; ++i){
        printf("%d %d %d\n",kedges[i]->u,kedges[i]->v,kedges[i]->w);
    }
}

void sol()
{
    //test
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
    mstkruskal();

    return 0;
}

/*
Sunday 29 November 2020 12:00:36 PM IST
     author:   __astrainL3gi0N
*/
