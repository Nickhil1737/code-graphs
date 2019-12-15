#include<iostream>
#include<vector>
using namespace std;

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
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>adj [n];
	for(int i = 0; i < m; ++i){
		int v,w;	cin>>v>>w;
		addedge(adj,v,w);
	}
	printedges(adj,n);

	return 0;
}

