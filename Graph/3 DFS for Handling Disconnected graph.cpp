#include<bits/stdc++.h>
using namespace std;

class Graph{
	void DFSUtil(int v);
	public:
		map<int, bool> visited;
		map<int, list<int> > adj;
		
		void addEdge(int v, int w);
		
		void DFS();
		
};

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v){
	visited[v] = true;
	cout<<v<<" ";
	
	list<int>::iterator i;
	for(i = adj[v].begin();i!=adj[v].end();++i){
		if(!visited[*i]){
			DFSUtil(*i);
		}
	}
}

void Graph::DFS()
{
	for(auto i: adj){
		if(visited[i.first] == false){
			DFSUtil(i.first);
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

	cout << "Following is Depth First Traversal \n";
	g.DFS();
}




