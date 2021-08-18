#include<bits/stdc++.h>
using namespace std;


int nCr(int n, int r){
	if(n<r){
		return 0;
	}
	if((n-r) < r){
		r = n-r;
	}
	int mod = 1000000007;
	
	int dp[r+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0;i<=n;i++){
		for(int j=min(r,i); j>0;j--){
			dp[j] = (dp[j] + dp[j-1])%mod;
		}
	}
	return dp[r];
}

int main(){
	int n,r;
	cin>>n>>r;
	cout<<nCr(n,r);
}
