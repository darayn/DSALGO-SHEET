#include<bits/stdc++.h>
using namespace std;

void isSubset(int * arr1, int * arr2, int n, int m){
	if(m>n){
		cout<<"No";
		return;
	}
	sort(arr1,arr1+n);
    sort(arr2,arr2+m);
	int count = 0;
	int i=0,j=0;
	while(i<n && j<m){
		if(arr1[i] == arr2[j]){
			i++;
			j++;
			count++;
		}
		else if(arr1[i]<arr2[j]){
			i++;
		}
		else if(arr1[i]>arr2[j]){
			j++;
		}
	}
	if(count==m){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	int *arr1 = new int[n];
	int *arr2 = new int[m];
	
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	isSubset(arr1,arr2,n,m);
}
