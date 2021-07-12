#include<bits/stdc++.h>
using namespace std;
vector<int> valueEqualToIndex(int *arr, int n){
	vector<int> v;
	for(int i=0;i<n;i++){
		if(i+1 == arr[i]){
			v.push_back(arr[i]);
		}
		
	}
	return v;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> res = valueEqualToIndex(arr,n);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
}
