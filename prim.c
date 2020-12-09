#include<stdio.h>
#include<stdlib.h>

int V, E;
struct node{
    int v, w;
    struct node *next;
}*adj[1000];
void addweightedEdge(int u, int v, int w){
    struct node *wedge = (struct node *)malloc(sizeof(struct node));
    wedge->v = v;
    wedge->w = w;
    wedge->next = NULL;
    struct node *wedge2 = (struct node *)malloc(sizeof(struct node));
    wedge2->v = u;
    wedge2->w = w;
    wedge2->next = NULL;
    adj[v] = wedge2;
}
int indx[10000], key[10000], parent[10000],marked[10000];
int N = 8;
int pq[1000] ;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void decreasekey(int r, int v)
{
    pq[indx[r]] = v;
    int k = indx[r];
    while(k > 1 && pq[k/2] > pq[k]){
        swap(&pq[k/2],&pq[k]);
        swap(&indx[k/2],&indx[k]);
        swap(&key[k/2],&key[k]);
        k = k/2;
    }

}
void minheapify(int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int smallest;
    if( l <= N && pq[l] < pq[i])
        smallest = l;
    else    smallest = i;
    if( r <= N && pq[r] < pq[smallest])
        smallest = r;
    if(smallest != i){
        swap(&pq[smallest],&pq[i]);
        minheapify(smallest);
    }
}
int extractmin()
{
    if(N == 0)  return 0;
    int nax = pq[1];
    pq[1] = pq[N--];
    minheapify(1);
    return nax;
}
void mstprim(int r)
{
    for(int i = 1; i < V+1; ++i){
        key[i] = 1e9,parent[i] = -1;
        indx[i] = i;pq[i] = key[i];
        marked[i] = 0;
    }

    decreasekey(r,0);
    int u;
    while(u = extractmin()){
        marked[u] = 1;
        struct node *v = adj[u];
        while(v != NULL){
            if(!marked[v->v] && v->w< key[v->v]){
                parent[v->v] = u;
                decreasekey(v->v,v->w);
            }
            v = v->next;
        }
    }
    int sum = 0;
    for(int i = 1; i < V+1; ++i){
        if(i == r)  continue;
        printf("%d %d \n",i,parent[i]);
        sum += key[i];
    }
    printf("sum : %d ",sum);

}
int main()
{
    scanf("%d %d ", &V,&E);
    for(int i = 0; i < E; ++i){
        int u,v,w;  
        scanf("%d %d %d ",&u,&v,&w);
        addweightedEdge(u,v,w);
    }

    mstprim(1);
    
    return 0;
}


/*
Wednesday 09 December 2020 08:27:47 PM IST
     author:   __astrainL3gi0N
*/
