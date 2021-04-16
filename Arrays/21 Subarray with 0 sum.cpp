#include<bits/stdc++.h>
using namespace std;

void isEqualtoZero(int *arr, int n){
	int sum = 0;
	unordered_set<int> m;
	for(int i=0;i<n;i++){
		sum+= arr[i];
		if(sum==0 || m.find(sum) != m.end()){
			cout<<"Yes";
			return;
		}
		
		m.insert(sum);
		
	}
	cout<<"No";
	return;
}


int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	isEqualtoZero(arr,n);
}
