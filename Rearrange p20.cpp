#include <bits/stdc++.h>
using namespace std;
void reArrange(int arr[], int n){
	int pivot = -1;
	for(int j=0;j<n;j++){
		if(arr[j] < 0){
			pivot++;
			swap(arr[pivot], arr[j]);
		}
	}
	int pos= pivot + 1;
	int neg = 0;
	while(pos < n && neg < pos && arr[neg]<0){
		swap(arr[neg], arr[pos]);
		pos++;
		neg+=2;
	}
	
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	reArrange(arr,n);
	int temp = arr[0];
	for(int i=0;i<n-1;i++){
		arr[i] = arr[i+1];
	}
	arr[n-1] = temp;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
}
