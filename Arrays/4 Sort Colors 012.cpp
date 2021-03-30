#include<bits/stdc++.h>
using namespace std;
void sort_012(int *arr, int n){
	int low = 0;
	int mid = 0;
	int high = n-1;
	while(mid<=high){
		if(arr[mid] == 0){
			swap(arr[low++], arr[mid++]);
		}
		else if(arr[mid] == 1){
			mid++;
		}
		else{
			swap(arr[mid],arr[high--]);
		}
	}
}
int main(){
	int n;
	cin>>n;
	int * arr = new int [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort_012(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

