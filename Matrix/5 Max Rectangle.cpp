#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(int *heights, int n){
	vector<int> right(n,n);
	vector<int> left(n,0);
	stack<int> temp;
	
	for(int i=0;i<n;i++){
		while(!temp.empty() && heights[temp.top()]>heights[i]){
			right[temp.top()] = i;
			temp.pop();
		}
		temp.push(i);
	}
	stack<int> temp1;
	
	for(int i=n-1;i>=0;i--){
		while(!temp1.empty() && heights[temp1.top()]>heights[i]){
			left[temp1.top()] = i+1;
			temp1.pop();
		}
		temp1.push(i);
	}
	
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans, heights[i]*right[i]-left[i]);
	}
	
	return ans;
}
int maxRectangle(int **M, int r, int c){
	if(r==0){
		return 0;
	}
	int** vec = new int* [r];
	for(int i=0;i<r;i++){
		vec[i] = new int[c];
		for(int j=0;j<c;j++){
			vec[i][j] = 0;
		}
	}
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i==0){
				vec[i][j] = M[i][j];
			}
			else{
				if(M[i][j] == 1){
					vec[i][j] = 1+vec[i-1][j];
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<r;i++){
		ans = max(ans, largestRectangleArea(vec[i], c));
	}
	return ans;
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
	cout<<maxRectangle(M, r, c);
}
