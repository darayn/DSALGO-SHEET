#include<bits/stdc++.h>
using namespace std;

void rotate90clockwise(int **arr, int n){
	for(int j=0;j<n;j++){
		for(int i=n-1;i>=0;i--){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int main(){
	int n;
	cin>>n;
	int **arr = new int*[n];
	for(int i=0;i<n;i++){
		arr[i] = new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	rotate90clockwise(arr,n);
}
