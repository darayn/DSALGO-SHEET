#include<bits/stdc++.h>
using namespace std;

int calculate_pairs(int *arr, int n, int k){
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		m[arr[i]]++;
	}
	int twice_count = 0;
	for(int i=0;i<n;i++){
		twice_count += m[k-arr[i]];
		
		if(k-arr[i] == arr[i]){
			twice_count--;        
		}
	}
	return twice_count/2;
}
int main(){
	int n,k;
	cin>>n>>k;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		
	}
	
	cout<<calculate_pairs(arr,n,k);
}


