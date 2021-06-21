#include<bits/stdc++.h>
#include<string.h>

using namespace std;
int first_occurence(int *arr, int low, int high, int x, int n){
	
	if(high>=low){
		int mid = low + (high-low)/2;
		if((mid==0 || x>arr[mid-1]&& x==arr[mid])){
			return mid;
		}
		else if(x>arr[mid]){
			return first_occurence(arr, (mid+1), high, x, n);
		}
		else{
			return first_occurence(arr, low, (mid-1), x, n);
		}
	}
	return -1;
}
int last_occurence(int *arr, int low, int high, int x, int n){
	
	if(high>=low){
		int mid = low + (high-low)/2;
		if((mid==n-1 || x<arr[mid+1] && x==arr[mid])){
			return mid;
		}
		else if(x<arr[mid]){
			return last_occurence(arr, low, (mid-1), x, n);
			
		}
		else{
			return last_occurence(arr, (mid+1), high, x, n);
		}
	}
	return -1;
}

int main(){
	int n,x;
	cin>>n>>x;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<first_occurence(arr, 0, n-1, x,n)<<" ";
	cout<<last_occurence(arr, 0, n-1, x,n);
}
