#include<bits/stdc++.h>
using namespace std;

class Graph{
	public:
		map<int, bool> visited;
		map<int, list<int> > adj;
		
		void addEdge(int v, int w);
		
		void DFS(int v);
		
};

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFS(int v){
	visited[v] = true;
	cout<<v<<" ";
	
	list<int>::iterator i;
	for(i = adj[v].begin();i!=adj[v].end();++i){
		if(!visited[*i]){
			DFS(*i);
		}
	}
}

int main(){
	Graph g;
	int n;
	cout<<"Enter number of edges"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}
	int start;
	cout<<"Enter starting vertex"<<endl;
	cin>>start;
	cout<<"Following is Depth First Traversal (starting from vertex "<<start<<" )"<<endl;
	g.DFS(start);
}




