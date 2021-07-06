#include<bits/stdc++.h>
using namespace std;
int count_of_coins(int *coin, int amount, int n){
	int *dp = new int[amount+1];
    dp[0] = 1;
    for(int i=0;i<n;i++){
    	for(int j=coin[i];j<amount+1;j++){
    		dp[j] += (dp[j-coin[i]]);
		}
	}
	
	return dp[amount];
}
int main(){
	int n;
	cin>>n;
	int amount;
	cin>>amount;
	int * coin = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	cout<<count_of_coins(coin, amount, n);
}
