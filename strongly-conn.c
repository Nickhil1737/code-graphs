#include<stdio.h>
#include<stdlib.h>

int V, E, dfstime,dfsId;
int finished[1000],discover[1000], marked[1000];
int finishedOrder[1000], dfsIds[1000];

struct node{
    int info;
    struct node * next;
}*adj[100],*adjT[1000], *head;
void addEdge(struct node *adj[], int x , int y)
{
    struct node* edge = (struct node *) malloc(sizeof(struct node));
    edge->info = y;
    edge->next = adj[x];
    adj[x] = edge;
}
void insertnode(int k)
{
    struct node *x = (struct node*)malloc(sizeof(struct node));
    x->info = k;
    x->next = head;
    head = x;
}

void dfsvisit(struct node *adj[], int s)
{
    discover[s] = ++dfstime;
    marked[s] = 1,dfsIds[s] = dfsId;
    struct node *x = adj[s];
    while(x != NULL){
        if(!marked[x->info])
            dfsvisit(adj,x->info);
        x = x->next;
    }
    finished[s] = ++dfstime;
}
void dfs(struct node **adj)
{
    for(int i = 1; i < V+1; ++i)
        marked[i] = 0;
    dfstime = 0;
    for(int i = 1; i < V+1; ++i)
        if(!marked[i]){
            dfsId = i;
            dfsvisit(adj,i);
        }
}

void dfsconn(struct node **adj)
{
    dfstime = 0;
    for(int i = 1; i < V+1; ++i){
        finishedOrder[finished[i]] = i;
        marked[i] = 0;
    }
    // calling dfsvisit() in order of decreasing u.f
    for(int i = 2*V; i > 0; --i){
        if(finishedOrder[i] && !marked[finishedOrder[i]]){
            dfsId = i;
            dfsvisit(adjT, finishedOrder[i]);
        }
    }

}

int main()
{
    scanf("%d %d",&V,&E);

    for(int i = 0; i < E; ++i){
        int x,y;    scanf("%d %d", &x,&y);
        addEdge(adj,x,y);

    }
    dfs(adj);

    // constructing graph's transpose
    for(int i = 1; i < V+1; ++i){
        struct node *x = adj[i];
        while(x != NULL){
            addEdge(adjT,x->info,i);
            x = x->next;
        }
        
    }
    dfsconn(adjT);
    printf("\nthe strongly connected verices have same ids : \n");
    for(int i = 1; i < V+1; ++i)
        printf("%d ",dfsIds[i]);

    
    

    return 0;
}

/*
Sunday 29 November 2020 12:00:36 PM IST
     author:   __astrainL3gi0N
*/
