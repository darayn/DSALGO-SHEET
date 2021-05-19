#include<bits/stdc++.h>
using namespace std;

int first(int *arr, int low, int high){
	if(high>= low){
		int mid = low + (high - low) /2 ;
		if((mid == 0|| arr[mid-1] == 0) && arr[mid] == 1){
			return mid;
		}
		
		else if(arr[mid] == 0){
			return first(arr, (mid + 1), high);
		}
		else{
			return first(arr,low,(mid-1));
		}
	}
	return -1;
}

int getMaxonesRowWise(int ** m,int r,int c){
	int max_row_index = 0, max= 0;
	int i, index;
	for(i=0;i<r;i++){
		index = first(m[i], 0, c-1);
		if(index!= -1&& c-index> max){
			max=c-index;
			max_row_index = i;
		}
	}
	return max_row_index;
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
	cout<<getMaxonesRowWise(M, r, c);
}
