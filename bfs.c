#include<stdio.h>
#include<stdlib.h>

int V, E;
int parent[1000],dist[1000], marked[1000];

struct node{
    int info;
    struct node * next;
}*adj[100], *front, *rear;
void addEdge(int x , int y)
{
    struct node* edge = (struct node *) malloc(sizeof(struct node));
    edge->info = y;
    edge->next = adj[x];
    adj[x] = edge;
}

int isEmpty(){
    return front==NULL;
}
void enqueue(int v){
    struct node *x = (struct node *) malloc(sizeof(struct node));
    x->info = v, x->next = NULL;
    if(isEmpty()){
        front = rear = x;
        return;
    }
    rear->next = x;
    rear = x;
}
int dequeue(){
    if(isEmpty())
        return -1;
    if(front == rear){
        rear = NULL;
    }
    int v = front->info;
    front = front->next;
    return v;
}


void bfs(int s)
{
    for(int i = 1; i < V+1; ++i){
        parent[i] = -1,dist[i] = 1e9, marked[i] = 0;
    }
    enqueue(s);
    dist[s] = 0, marked[s] = 1, parent[s] = -1;

    while(!isEmpty())
    {
        int u = dequeue();
        struct node *x = adj[u];
        while(x != NULL){
            int v = x->info;
            if(!marked[v]){
                parent[v] = u,dist[v] = 1+dist[u],marked[v]=1;
                enqueue(v);
            }
            x = x->next;
        }
        
    }
}

int main()
{
    scanf("%d %d",&V,&E);

    for(int i = 0; i < E; ++i){
        int x,y;    scanf("%d %d", &x,&y);
        addEdge(x,y);

    }

    for(int i = 1; i < V+1; ++i){
        struct node *x = adj[i];
        printf("\n%d  - ",i);
        while(x != NULL){
            printf("%d ",x->info);
            x = x->next;
        }
        
    }
    bfs(1);
    for(int i = 1; i < V+1; ++i)   printf("%d ",dist[i]);
    printf("\n");
    for(int i = 1; i < V+1; ++i)   printf("%d ",parent[i]);

    return 0;
}

/*
Saturday 28 November 2020 04:24:00 PM IST
     author:   __astrainL3gi0N
*/
