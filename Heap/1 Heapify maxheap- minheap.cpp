#include<bits/stdc++.h>
using namespace std;

void min_heapify(int *arr, int n, int i){
	int shortest = i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l] < arr[shortest]){
		shortest = l;
	}
	if(r<n && arr[r] < arr[shortest]){
		shortest = r;
	}
	if(shortest!= i){
		swap(arr[i], arr[shortest]);
		min_heapify(arr, n, shortest);
	}
}

void heapify(int *arr, int n, int i){
	int largest = i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l] > arr[largest]){
		largest = l;
	}
	if(r<n && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest!= i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void buildHeap(int *arr, int n){
	int startIdx = (n/2) - 1;
	for(int i=startIdx;i>=0;i--){
		min_heapify(arr, n, i);
	}
}
void printHeap(int *arr, int n){
	cout<<"Array representation of Heap is : \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	int n;
	cin>>n;
	int *arr =new int[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	buildHeap(arr, n);
	printHeap(arr, n);
	
}
