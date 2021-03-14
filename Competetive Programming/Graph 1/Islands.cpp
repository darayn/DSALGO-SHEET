/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 

*/

#include<bits/stdc++.h>
using namespace std;
void print(int** arr,int n, int starting_index,bool* visited){
	queue<int> q;
	q.push(starting_index);
	visited[starting_index] = true;
	while(!q.empty()){
//		cout<<q.front()<<" ";
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
	int cnt=0;
	for(int i=0;i<v;i++){
		if(!visited[i]){
			print(arr,v,i,visited);
			cnt++;
		}
        // cout<<visited[i]<<" ";
	}
	cout<<cnt;
	return 0;
}
