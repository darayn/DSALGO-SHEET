#include<bits/stdc++.h>
using namespace std;


int getMedianRowWise(int **m, int r, int c){
	int min = INT_MAX;
	int max = INT_MIN;
	for(int i=0;i<r;i++){
		if(m[i][0] < min){
			min = m[i][0];
		}
		if(m[i][c-1]){
			max = m[i][c-1];
		}
	}
	int desired =  (r*c +1)/2;
	while(min<max){
		int mid = min + (max-min) / 2;
		int count = 0;
		for(int i=0;i<r;i++){
			count+= upper_bound(m[i],m[i] + c,mid) - m[i];
			
		}
		if(count<desired){
			min = mid + 1;
		}
		else{
			max =mid;
		}
	}
	return min;
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
	cout<<getMedianRowWise(M, r, c);
}
