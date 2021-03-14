
int knapsack_helper(int* weight, int* value, int n, int maxWeight, int ** dp){
    if (n == 0 || maxWeight == 0) 
        return 0; 
    
    if(dp[n][maxWeight] > -1){
        return dp[n][maxWeight];
    }
    int ans = 0;
    if (weight[n - 1] > maxWeight){
        ans = knapsack_helper(weight, value,n-1, maxWeight,dp);
        dp[n][maxWeight] = ans;
    	return ans;
    }
    else{
        ans = max(value[n-1] + knapsack_helper(weight, value,n-1, maxWeight - weight[n-1],dp),
                 knapsack_helper(weight, value,n-1, maxWeight,dp)
                 );
        dp[n][maxWeight] = ans;
    	return ans;
    }
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	int **dp = new int * [n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int [maxWeight+1];
        for(int j=0;j<=maxWeight;j++){
            dp[i][j] = -1;
        }
    }
    
    int ans =  knapsack_helper(weight, value, n, maxWeight, dp);
    return ans;
}
