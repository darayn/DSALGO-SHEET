#include<bits/stdc++.h>
using namespace std;
int maxdiffpair(int **m, int r,int c){
	int max_value = INT_MIN;
	int maxArr[r][c];
	
	maxArr[r-1][c-1] = m[r-1][c-1];
	int maxv = m[r-1][c-1];
	for(int j=c-2;j>=0;j--){
		if(m[r-1][j]>maxv){
			maxv=m[r-1][j];
		}
		maxArr[r-1][j]=maxv;
	}	
	maxv = m[r-1][c-1];
	for(int j=r-2;j>=0;j--){
		if(m[j][c-1]>maxv){
			maxv=m[j][c-1];
		}
		maxArr[j][c-1]=maxv;
	}	
	
	for(int i=r-2;i>=0;i--){
		for(int j=c-2;j>=0;j--){
			if(maxArr[i+1][j+1] - m[i][j] > max_value){
				max_value= maxArr[i+1][j+1]-m[i][j];
			}
			maxArr[i][j] = max(m[i][j], max(maxArr[i][j+1],maxArr[i+1][j]));
		}
	}
	return max_value;
}


int main(){
	int r,c;
	cin>>r>>c;
	int** M = new int* [r];
	for(int i=0;i<r;i++){
		M[i] = new int[c];
		for(int j=0;j<c;j++){
			cin>>M[i][j];
		}
	}
	cout<<maxdiffpair(M, r, c);
}
