#include <bits/stdc++.h>
using namespace std; 
void merge(int arr1[], int arr2[], int n, int m) {
	    int p = n-1;
	    int q = 0;
	    while(p>=0 && q<m){
	        if(arr1[p]>arr2[q]){
	            swap(arr1[p],arr2[q]);
	        }
	        else{
	            break;
	        }
	        p--;
	        q++;
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
}
int main(){
	int n,m;
	cin>>n>>m;
	int arr1[n];
	int arr2[m];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	merge(arr1,arr2,n,m);
	for(int i=0;i<n;i++){
		cout<<arr1[i]<<" ";
	}
	for(int i=0;i<m;i++){
		cout<<arr2[i]<<" ";
	}
}
