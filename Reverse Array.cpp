#include<bits/stdc++.h>
using namespace std;
void reverse_array(int arr[],int start,int end){
	while(start<end){
		int temp =arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		
	}
	
	reverse_array(arr, 0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
		
	}
	
}
