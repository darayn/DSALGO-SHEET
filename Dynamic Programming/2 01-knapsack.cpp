#include<bits/stdc++.h>
using namespace std;
int static dp[1002][1002];

int knapSackUtil(int wt[], int val[], int W, int n){
    if(n==0 || W==0){
        return 0;
    }
    if(dp[n][W] != -1){
        return dp[n][W];
    }
    if(wt[n-1]<=W){
        dp[n][W] = max(val[n-1] + knapSackUtil(wt,val,W-wt[n-1],n-1) ,knapSackUtil(wt,val,W,n-1) );
    }
    else if(wt[n-1]>W){
        dp[n][W] = knapSackUtil(wt,val,W,n-1);
    }
    return dp[n][W];
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
   
    memset(dp,-1,sizeof(dp));
    int ans = knapSackUtil(wt, val, W, n);
    return ans;
}


int main()
 {
    int n, w;
    cin>>n>>w;
    
    int val[n];
    int wt[n];
    
    for(int i=0;i<n;i++){
    	cin>>val[i];
	}
    for(int i=0;i<n;i++){
    	cin>>wt[i];
	}
        
 
    cout<<knapSack(w, wt, val, n)<<endl;
    
	return 0;
}  
