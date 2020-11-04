#include <bits/stdc++.h>
using namespace std;
int findDuplicate(int *arr,int n){
	sort(arr,arr+n);
	for(int i=1;i<n;i++){
		if(arr[i] == arr[i-1]){
			return arr[i];
		}
		
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Duplicate Element : "<<findDuplicate(arr,n);
	delete [] arr;
}
