#include<bits/stdc++.h>
using namespace std;

int kadane_maxcontsum(int *arr, int n){
	int max_sum = arr[0];
	for(int i=1;i<n;i++){
		arr[i] = max(arr[i],arr[i] + arr[i-1]);
		if(arr[i]>max_sum){
			max_sum = arr[i];
		}
	}
	return max_sum;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<kadane_maxcontsum(arr, n);
}
