#include<bits/stdc++.h>

#include <vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void printGraph(vector<int> adj[], int V){
	for(int v=0;v<V;v++){
		cout<<"Adjacency list of vertex "<<v<<"\n head ";
		for(auto x: adj[v]){
			cout<<"-> "<<x;
		}
		printf("\n");
	}
}
int main(){
	cout<<" Enter No. of vertex"<<endl;
	int V,n;
	cin>>V;
	vector<int> adj[V];
	cout<<"Enter No of edges"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter Edge "<<i+1<<endl;
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	}
	printGraph(adj,V);
}
