#include<bits/stdc++.h>
using namespace std;

int buyAndsell(int *prices, int n){
	int min_till_here = prices[0];
	int profit = 0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]<min_till_here){
            min_till_here = prices[i];
        }
         
        profit = max(prices[i]-min_till_here,profit);
    }
    return profit;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<"Maximum Profit: "<<buyAndsell(arr,n);
	return 0;
}
