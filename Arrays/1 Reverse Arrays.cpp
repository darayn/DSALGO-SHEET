#include<bits/stdc++.h>
using namespace std;

void reverseArr(int *arr, int n){
	int start = 0;
	int end = n-1;
	while(start<end){
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
void reverseArrRecursive(int *arr, int start, int end){
	
	if(start>=end){
		return;
	}
	int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseArrRecursive(arr, start + 1, end - 1);

}
int main(){
	int n;
	cin>>n;
	int * arr = new int [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//reverseArr(arr, n);
	
	reverseArrRecursive(arr,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
