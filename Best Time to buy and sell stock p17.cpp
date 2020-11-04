#include <bits/stdc++.h>

using namespace std;
int max_profit(int arr[],int n){
	int min_p = INT_MAX;
	int max_p = 0;
	for(int i=0;i<n;i++ ){
		if(arr[i]<min_p){
			min_p = arr[i];
		}
		else if(arr[i]-min_p > max_p){
			max_p = arr[i] - min_p;
		}
	}
	
	return max_p;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<max_profit(arr,n)<<endl;
}
