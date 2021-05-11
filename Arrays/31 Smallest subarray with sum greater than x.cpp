#include<bits/stdc++.h>
using namespace std;
int smallest_subarray_size(arr, n, x){
	int curr_sum = 0;
	int min_len = n+1;
	int start = 0, end = 0;
	while(end<n){
		while(curr_sum <= x&& end<n){
			curr_sum+= arr[end++];
		}
		while(curr_sum>x && start<n){
			if(end-start< min_len){
				min_len = end - start;
			}
			
			curr_sum-= arr[start++];
		}
	}
	return min_len;
}
int main(){
	int n,x;
	cin>>n>>x;
	int *arr = new int [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<smallest_subarray_size(arr, n, x);
}
