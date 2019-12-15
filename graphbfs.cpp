#include<iostream>
#include<vector>
using namespace std;

bool *marked;
int *distTo;
int *edgeTo;

void addEdge(vector<int> adj[],int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void bfs(vector<int> adj[], int n, int v)
{
	marked = new bool[n];
	edgeTo = new int[n];
	distTo = new int[n];
	vector<int> q;
	q.push_back(v);
	marked[v] = 1;
	while(!q.empty()){

		int t = *q.begin();
		//cout<<t<<'\n';
		q.erase(q.begin());
		for(int v = 0; v < adj[t].size(); ++v){
			if(!marked[adj[t][v]]){
				marked[adj[t][v]] = 1;
				q.push_back(adj[t][v]);
				edgeTo[adj[t][v]] = t;
				distTo[adj[t][v]] = distTo[t] + 1;
			}
		}
		//for(int i = 0; i < q.size(); ++i)	cout<<q[i]<<' ';
		//cout<<"t = "<<t<<'\n';
	}


}

void printEdge(vector<int> adj[], int n){
	for(int i = 0; i < n; ++i){
		cout<<i<<"\t";
		for(int j = 0; j < adj[i].size(); ++j)
			cout<<adj[i][j]<<' ';
		cout<<'\n';
	}
	cout<<"marked\t";
	for(int i = 0; i < n; ++i)	cout<<marked[i]<<' ';
	cout<<'\n';
	cout<<"edge to\t";
	for(int i = 0; i < n; ++i)	cout<<edgeTo[i]<<' ';
	cout<<'\n';
	cout<<"dist to\t";
	for(int i = 0; i < n; ++i)	cout<<distTo[i]<<' ';
	cout<<'\n';
}


int main()
{
	int n, m;	cin>>n>>m;
	vector<int> adj[n+1];

	for(int i = 0; i < m; ++i){
		int v,w;	cin>>v>>w;
		addEdge(adj,v,w);
	}
	bfs(adj,n+1,2);
	printEdge(adj, n+1);
	return 0;
}
