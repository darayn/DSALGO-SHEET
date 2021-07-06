#include<bits/stdc++.h>

#define max_r 100
#define max_c 100
using namespace std;
bool isSafe(int row, int col, int m[max_r][max_c], int r, int c, bool visited[max_r][max_c]){
	if(row==-1||row==r||col==-1||col==c||visited[row][col]||m[row][col] == 0){
		return false;
	}
	return true;
}
void printPathUtil(int row, int col, int m[max_r][max_c], int r, int c, string& path, vector<string>& possiblePaths, bool visited[max_r][max_c]){
	if(row==-1 || row == r || col==-1 || col == c|| visited[row][col] || m[row][col]){
		return;
	}
	if(row == r-1 && col == c-1){
		possiblePaths.push_back(path);
		return;
	}
	visited[row][col] = true;
	if(isSafe(row+1,col,m,r,c, visited)){
		path.push_back('D');
		printPathUtil(row+1,col,m, r,c ,path, possiblePaths, visited);
		path.pop_back();
	}
	if(isSafe(row,col-1,m,r,c, visited)){
		path.push_back('L');
		printPathUtil(row,col-1,m, r,c, path, possiblePaths, visited);
		path.pop_back();
	}
	if(isSafe(row,col+1,m,r,c, visited)){
		path.push_back('R');
		printPathUtil(row,col+1,m, r,c, path, possiblePaths, visited);
		path.pop_back();
	}
	if(isSafe(row-1,col,m,r,c, visited)){
		path.push_back('U');
		printPathUtil(row-1,col,m, r,c, path, possiblePaths, visited);
		path.pop_back();
	}
	
	visited[row][col] = false;
}

void printPath(int m[max_r][max_c], int r, int c){
	vector<string> possiblePaths;
	string path;
	bool visited[r][c];
	memset(visited, false, sizeof(visited));
	printPathUtil(0,0,m,r,c, path, possiblePaths, visited);
	
	for(int i=0;i<possiblePaths.size();i++){
		cout<< possiblePaths[i]<<" ";
	}
	
}
int main(){
	int r,c;
	cin>>r>>c;
//	max_r = r;
//	max_c = c;
	int m[r][c];
	for(int i=0;i<r;i++){
		for(int j=0; j<c;j++){
			cin>>m[i][j];
		}
	}
	printPath(m,r,c);
}
