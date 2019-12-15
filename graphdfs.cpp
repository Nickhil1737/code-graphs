#include<iostream>
#include<vector>
using namespace std;

bool *marked;
int *edgeto;

void addedge(vector<int> adj[], int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void printedges(vector<int> adj[], int n){
	for(int i = 0; i < n; ++i){
		cout<<i<<'\t';
		for(int j = 0; j < adj[i].size(); ++j)
			cout<<adj[i][j]<<' ';
		cout<<'\n';
	}
}

void dfs(vector<int> adj[], int v){
	marked[v] = 1;
	for(int i = 0; i < adj[v].size(); ++i)
		if(!marked[adj[v][i]]){
			edgeto[adj[v][i]] = v;
			dfs(adj,adj[v][i]);
		}
}

void dfs(vector<int> adj[], int n, int v){
	marked = new bool[n+1];
	edgeto = new int[n+1];

	dfs(adj,1);
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>graphg [n+1];
	for(int i = 0; i < m; ++i){
		int v,w;	cin>>v>>w;
		addedge(graphg,v,w);
	}
	dfs(graphg, n,1);
	printedges(graphg,n+1);
	
	cout<<"marked\t";
	for(int i = 0; i <= n; ++i)
		cout<<marked[i]<<' ';
	cout<<"\n edge to \t";
	for(int i = 0; i <= n; ++i)
		cout<<edgeto[i]<<' ';

	return 0;
}

