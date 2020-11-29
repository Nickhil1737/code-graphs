#include<bits/stdc++.h>
using namespace std;

vector < vector <int> > adj;
int V,E;
int dist[110];
bool marked[110];
int parent[110];

void bfs(int s)
{
    for(int i = 1; i < V+1; ++i){
        parent[i] = -1;
        dist[i] = 1e9;
        marked[i] = 0;
    }
    dist[s] = 0,marked[s] = 1,parent[s] = -1;

    queue < int > Q;    Q.push(s);

    while(!Q.empty())
    {
        int u = Q.front();  Q.pop();
        for(auto v: adj[u])
            if(!marked[v]){
                parent[v] = u;
                dist[v] = dist[u]+1;
                marked[v] = 1;
                Q.push(v);
            }
        
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
    for(int i = 1; i < V+1; ++i){
        cout<<i<<'\t';
        for(auto v:adj[i])
            cout<<v<<' ';
        cout<<'\n';
    }
    bfs(1);

    for(int i = 0; i < V+1; ++i)
        cout<<dist[i]<<(i==V?'\n':' ');
    for(int i = 0; i < V+1; ++i)
        cout<<marked[i]<<(i==V?'\n':' ');

    return 0;
}
