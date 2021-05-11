#include<bits/stdc++.h>
using namespace std;
void threeWayPartition(int *arr, int n, int low, int high){
	int start = 0;
	int end = n-1;
	for(int i=0;i<=end;){
		if(arr[i]<low){
			swap(arr[i++], arr[start++]);
			
		}
		else if(arr[i]>high){
			swap(arr[i], arr[end--]);
		}
		else{
			i++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}


int main(){
	int n;
	cin>>n;
	int *arr = new int [n];
	int low,high;
	cin>>low>>high;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	threeWayPartition(arr, n, low, high);
}
