/*
Given two strings, S and T with lengths M and N, find the length of the 'Longest Common Subsequence'.
For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.
Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the length of the 'Longest Common Subsequence'.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1sec
Sample Input 1 :
adebc
dcadb
Sample Output 1 :
3
Explanation of the Sample Input 1 :
Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3. 
Sample Input 2 :
ab
defg
Sample Output 2 :
0
Explanation of the Sample Input 2 :
The only subsequence that is common to both the given strings is an empty string("") of length 0.

*/
#include<bits/stdc++.h>
using namespace std;
int lcs(char * s1, char * s2 ){
	if(s1[0]=='\0' || s2[0]=='\0'){
		return 0;
	}
	if(s1[0]==s2[0]){
		return 1 + lcs(s1+1,s2+1);
	}
	else{
		int option1 = lcs(s1,s2+1);
		int option2 = lcs(s1+1,s2);
		return max(option1,option2);
	}
}


int lcsI(char* s1,char* s2){
	int m = strlen(s1);
	int n = strlen(s2);
	int ** dp = new int *[m+1];
	for(int i=0;i<=m;i++){
		dp[i] =new int [n+1];
	}
	for(int i=0;i<=m;i++){
		dp[i][0] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[0][i] = 0;
	}
	for(int i = 1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s1[m-i] == s2[n-j]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int ans = dp[m][n];
	for(int i=0;i<=m;i++){
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
	
}

int lcs2helper(char * s1, char * s2 , int m, int n, int**dp){
	if(m==0 || n==0){
		return 0;
	}
	if(dp[m][n] > -1){
		return dp[m][n];
	}
	int ans;
	if(s1[0]==s2[0]){
		ans= 1 + lcs2helper(s1+1,s2+1,m-1,n-1,dp);
	}
	else{
		int option1 = lcs2helper(s1,s2+1, m,n-1,dp);
		int option2 = lcs2helper(s1+1,s2,m-1,n,dp);
		ans = max(option1,option2);
	}	
	dp[m][n] = ans;
	return ans;
}
int lcs2(char * s1, char * s2 ){
	int m = strlen(s1);
	int n = strlen(s2);
	int ** dp = new int *[m+1];
	for(int i=0;i<=m;i++){
		dp[i] =new int [n+1];
		for(int j=0;j<=n;j++){
			dp[i][j]=-1;
		}
	}
	int ans = lcs2helper(s1,s2,m,n,dp);
	for(int i=0;i<=m;i++){
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}

int main(){
	char a[100];
	char b[100];
	cin>>a;
	cin>>b;
	cout<<lcs2(a,b)<<endl;
	cout<<lcsI(a,b)<<endl;
	
}
