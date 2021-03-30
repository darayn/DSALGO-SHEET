#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	priority_queue<int> maxh;
	for(int i=0;i<n;i++){
		maxh.push(arr[i]);
		if(maxh.size()>k){
			maxh.pop();
		}
	}
	int output = maxh.top();
	cout<<output;
}
