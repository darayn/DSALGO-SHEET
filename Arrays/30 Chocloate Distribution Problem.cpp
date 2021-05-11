#include<bits/stdc++.h>
using namespace std;

int min_choclate_diff(int *arr, int n,int m){
	int min_diff = INT_MAX;
	sort(arr, arr+n);
	for(int i=0;i+m-1<n;i++){
		min_diff = min(min_diff, arr[i+m-1] - arr[i]);
	}
	return min_diff;
}
int main(){
	int n,m;
	cin>>n>>m;
	int *arr = new int [n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	cout<<min_choclate_diff(arr,n,m);
}
