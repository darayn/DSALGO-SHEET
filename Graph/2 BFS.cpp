#include<bits/stdc++.h>
#include<list>
using namespace std;
class Graph{
	int V;
	
	list<int> *adj;
	public: 
		Graph(int V);
		
		void addEdge(int v, int w);
		void BFS(int start);
};


Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::BFS(int start){
	bool *visited = new bool[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}
	
	list<int> queue;
	visited[start] = true;
	queue.push_back(start);
	list<int>::iterator i;
	while(!queue.empty()){
		start = queue.front();
		cout<<start<<" ";
		queue.pop_front();
		
		for(i = adj[start].begin(); i!= adj[start].end();i++){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
		
	}
}

int main(){
	int vertex;
	cin>>vertex;
	
	Graph g(vertex);
	int edges;
	cin>>edges;
	for(int i=0;i<edges;i++){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}
	int start_edge;
	cin>>start_edge;
	
	cout<< "Following is Breadth First Traversal "
         << "(starting from vertex "<<start_edge<<" ]) \n";
    g.BFS(start_edge);
}
