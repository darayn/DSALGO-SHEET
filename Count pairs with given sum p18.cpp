#include <bits/stdc++.h>
using namespace std;
 
int count_pair(int arr[], int n,int k){
	unordered_map <int, int> mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}
	int twice_count = 0;
	for(int i= 0;i<n;i++){
		twice_count += mp[k-arr[i]];
		
		if(k-arr[i] == arr[i]){
			twice_count--;
		}
	}
	return twice_count/2;
}
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<count_pair(arr,n,k)<<endl;
}
