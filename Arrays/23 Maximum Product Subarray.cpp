#include<bits/stdc++.h>
using namespace std;

int maxSubarrayProduct(int *arr, int n){
	int maxProduct = arr[0];
	int maxPositive = arr[0];
	int maxNegative = arr[0];
	
	for(int i=1;i<n;i++){
		int choice1 = maxPositive*arr[i];
		int choice2 = maxNegative*arr[i];
		
		maxPositive = max(choice1,max(choice2,arr[i]));
		maxNegative = min(choice1,min(choice2,arr[i]));
		
		maxProduct = max(maxProduct,max(maxPositive, maxNegative));
		
	}
	return maxProduct;
}


int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<maxSubarrayProduct(arr,n);
}
