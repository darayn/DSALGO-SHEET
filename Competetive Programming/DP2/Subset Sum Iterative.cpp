/*
You are given a set of N integers. You have to return true if there exists a subset that sum up to K, otherwise return false.
Input Format
The first line of the test case contains an integer 'N' representing the total elements in the set.

The second line of the input contains N integers separated by a single space.    

The third line of the input contains a single integer, denoting the value of K.
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Constraints :
1 <= N <= 10^6
1 <= a[i] <= 10^3, where a[i] denotes an element of the set 
1 <= K <= 10^3

Time Limit: 1 sec
Sample Input 1 :
4
4 3 5 2
13
Sample Output 1 :
No
Sample Input 2 :
5
4 2 5 6 7
14
Sample Output 2 :
Yes

*/
#include<bits/stdc++.h>
using namespace std;

bool subsetSum_recursive(int *arr, int n, int k,int **dp){
	if(k==0){
		return true;
		
	}
	if(n==0){
		return false;
	}
	if(dp[n][k]>=0){
		return dp[n][k];
	}
	int ans = 0;
	if(arr[0]<=k){
		bool option1 = subsetSum_recursive(arr+1, n-1, k,dp);
		bool option2 = subsetSum_recursive(arr+1,n-1, k-arr[0], dp);
		if(option1 || option2){
			ans = 1;
		}
	}
	else{
		ans = subsetSum_recursive(arr+1, n-1, k,dp);
	}
	dp[n][k] = ans;
	return ans;
}
bool subsetSum(int * val, int n, int sum){
	bool **dp = new bool*[2];
	for(int i=0;i<2;i++){
		dp[i] = new bool [sum+1];
	}
	for(int i=0;i<=sum;i++){
		dp[0][i] = false;
	}
	dp[0][0] = true;
	
	int flag = 1;
	
//	for(int i=0;i<=n;i++){
//		dp[i][0] = true;
//	}
	for(int i=1;i<=n;i++){
		for(int j = 1;j<=sum;j++){
			dp[flag][j] = dp[flag^1][j];
			if(j>=val[i-1]){
				dp[flag][j] = dp[flag][j] || dp[flag^1][j-val[i-1]] ;
			}
		}
		flag = flag^1;
	}
	bool ans = dp[flag^1][sum];
	return ans;
}

int main(){
	int  n;
	cin>>n;
	int *arr = new int [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	int **dp = new int *[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int [k+1];
		for(int j=0;j<=k;j++){
			dp[i][j] = -1;
		}
	}
	if(subsetSum_recursive(arr, n, k, dp)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	for(int i=0;i<=n;i++){
		delete[] dp[i];
	}
	delete []dp;
	
	cout<<subsetSum(arr, n, k);
}
