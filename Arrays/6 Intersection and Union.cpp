#include<bits/stdc++.h>
using namespace std;

void findUnion(int *arr1, int n, int *arr2, int m){
	
	map<int,int> mp;
	for(int i=0;i<n;i++){
		mp.insert({arr1[i], i});
	}
	for(int i=0;i<m;i++){
		mp.insert({arr2[i], i});
	}
	for(auto itr = mp.begin(); itr != mp.end(); itr++){
		cout<<itr->first<<" ";
	}
}

void findIntersection(int *arr1, int n, int *arr2, int m){
	set<int> intersect;
	for(int i=0;i<n;i++){
		intersect.insert(arr1[i]);
	}
	for(int i=0;i<m;i++){
		if(intersect.find(arr2[i]) != intersect.end()){
			cout<<arr2[i]<<" ";
		}
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
	findIntersection(arr1,n,arr2,m);
	cout<<endl;
	findUnion(arr1,n,arr2,m);
	
}
