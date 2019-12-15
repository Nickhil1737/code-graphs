#include<iostream>
#include<vector>
using namespace std;

bool *marked;
int *edgeto;
int *distTo;
void addedge(vector<int> adj[], int v, int w){
	adj[v].push_back(w);
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

	dfs(adj,v);
}

void bfs(vector<int> adj[], int n, int v)
{

	marked = new bool[n];
	edgeto = new int[n];
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
				edgeto[adj[t][v]] = t;
				distTo[adj[t][v]] = distTo[t] + 1;
			}
		}
		//for(int i = 0; i < q.size(); ++i)	cout<<q[i]<<' ';
		//cout<<"t = "<<t<<'\n';
	}

	cout<<"marked\t";
	for(int i = 0; i < n; ++i)	cout<<marked[i]<<' ';
	cout<<'\n';
	cout<<"edge to\t";
	for(int i = 0; i < n; ++i)	cout<<edgeto[i]<<' ';
	cout<<'\n';
	cout<<"dist to\t";
	for(int i = 0; i < n; ++i)	cout<<distTo[i]<<' ';
	cout<<'\n';

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
	dfs(graphg, n,3);
	printedges(graphg,n+1);
	cout<<"\tDFS\n";	
	cout<<"marked\t";
	for(int i = 0; i <= n; ++i)
		cout<<marked[i]<<' ';
	cout<<"\nedge to \t";
	for(int i = 0; i <= n; ++i)
		cout<<edgeto[i]<<' ';
	cout<<"\tBFS\n";	
	bfs(graphg,n+1,3);
	return 0;
}

