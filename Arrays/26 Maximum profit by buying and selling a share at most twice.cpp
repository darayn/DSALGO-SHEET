#include<bits/stdc++.h>
using namespace std;

int maxProfit(int *arr, int n){
	int *profit = new int[n];
	for(int i=0;i<n;i++){
		profit[i] = 0;
	}
	int maxPrice = arr[n-1];
	
	for(int i=n-2;i>=0;i--){
		if(arr[i]>maxPrice){
			maxPrice = arr[i];
		}
		
		profit[i] = max(profit[i+1], maxPrice-arr[i]);
	}
	
	int minPrice = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]<minPrice){
			maxPrice = arr[i];
		}
		profit[i] = max(profit[i-1], profit[i]+ (arr[i] - minPrice));
	}
	return profit[n-1];
	
	
}


int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<maxProfit(arr,n);
}
