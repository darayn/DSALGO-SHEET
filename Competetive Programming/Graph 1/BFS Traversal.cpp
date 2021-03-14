/*
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print the BFS Traversal, as described in the task.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2

*/

#include<bits/stdc++.h>
using namespace std;
void print(int** arr,int n, int starting_index,bool* visited){
	queue<int> q;
	q.push(starting_index);
	visited[starting_index] = true;
	while(!q.empty()){
		cout<<q.front()<<" ";
		int current_element = q.front();
		for(int i=1;i<n;i++){
			if(i==current_element){
				continue;
			}
			if(visited[i]){
				continue;
			}
			if(arr[current_element][i] == 1){
				q.push(i);
				visited[i] = true;
			}
		}
		q.pop();
	}
	
}
int main(){
	int v,e;
	cin>>v>>e;
	int **arr = new int*[v];
	for(int i=0;i<v;i++){
		arr[i] = new int[v];
		for(int j=0;j<v;j++){
			arr[i][j] = 0;
		}
	}
	while(e--){
		int a,b;
		cin>>a>>b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	bool* visited = new bool[v];
	for(int i=0;i<v;i++){
		visited[i] = false;
	}
	for(int i=0;i<v;i++){
		if(!visited[i]){
			print(arr,v,i,visited);
		}
	}
    
	
}
