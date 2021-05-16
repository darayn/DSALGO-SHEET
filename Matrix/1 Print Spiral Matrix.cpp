#include<bits/stdc++.h>
using namespace std;
//#define r
//#define c
void spiralMatrix(int **arr, int R, int C){
		int top = 0;
		int down = R-1;
		int left = 0;
		int right = C-1;
		int dir = 0;
		
		while( top<= down && left<=right){
			if(dir==0){
				for(int i=left;i<=right;i++){
					cout<<arr[top][i]<<" ";
				}
				top++;
			}
			else if(dir == 1){
				for(int i=top;i<=down;i++){
					cout<<arr[i][right]<<" ";
				}
				right--;
			}
			else if(dir == 2){
				for(int i=right;i>=left;i--){
					cout<<arr[down][i]<<" ";
				}
				down--;
			}
			else if(dir == 3){
				for(int i=down;i>=top;i--){
					cout<<arr[i][left]<<" ";
				}
				left++;
			}
			dir = (dir+1)%4;
		}
}

int main(){
	int r,c;
	cin>>r>>c;
//	int M[r][c];
	int** M = new int* [r];
	for(int i=0;i<r;i++){
		M[i] = new int[c];
		for(int j=0;j<c;j++){
			cin>>M[i][j];
		}
	}
	
	spiralMatrix(M,r,c);
}
