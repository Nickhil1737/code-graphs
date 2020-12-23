#include<bits/stdc++.h>
using namespace std;

vector < vector <int> > adj;
int V,E,dfstime;
int discover[110],finished[110],parent[110];
bool marked[110];

struct node{
    int info;
    node *next;
    node(int k){
        info = k;
        next = NULL;
    }
}*root;
node * insert(int k){
    if(root == NULL)
        return new node(k);
    node *x = new node(k);
    x->next = root;
    return x;
}


void dfsvisit(int s)
{
    discover[s] = ++dfstime;
    marked[s] = 1;
    for(auto v:adj[s])
        if(!marked[v])
            dfsvisit(v);
    finished[s] = ++dfstime;
    root = insert(s);
}
void dfs()
{
    for(int i = 1; i < V+1; ++i)
        parent[i] = -1,marked[i] = 0;
    dfstime = 0;

    for(int i = 1; i < V+1; ++i){
        if(!marked[i])
            dfsvisit(i);
    }
    
}


int main()
{
    cin>>V>>E;
    adj.resize(V+10);
    for(int i = 0; i < E; ++i){
        int x,y;    cin>>x>>y;
        adj[x].push_back(y);
    }
    dfs();

    for(int i = 0; i < V+1; ++i)
        cout<<discover[i]<<(i==V?'\n':' ');
    for(int i = 0; i < V+1; ++i)
        cout<<finished[i]<<(i==V?'\n':' ');
    node *x = root;
    // linked list consists topologically sorted vertices
    while(x != NULL){
        cout<<x->info<<(x->next==NULL?'\n':' ');
        x = x->next;
    }

    return 0;
}
