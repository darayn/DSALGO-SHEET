#include<bits/stdc++.h>
using namespace std;

int getMedian(int *arr1, int *arr2, int n, int m){
	int i=0;
	int j=0;
	int count = 0;
	int m1=-1;
	int m2=-1;
	for(count=0;count<=(n+m)/2;count++){
		if(i!=n && j!=m){
			m1 = (arr1[i]>arr2[j]) ? arr2[j++]: arr1[i++];
		}
		else if(i<n){
			m1 = arr1[i++];
		}
		else{
			m1 = arr2[j++];
		}
		
	}
	if((m+n)%2 == 1){
		return m1;
	}
	else{
		return (m1 + m2)/2;
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
	cout<<getMedian(arr1, arr2, n, m);
}

// econd Approach from https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
