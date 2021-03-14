/*
 Given two strings S and T with lengths M and N. Find and return the length of their shortest 'Super Sequence'.
 The shortest 'Super Sequence' of two strings is defined as the smallest string possible that will have both the given strings as its subsequences.
Note :
If the two strings do not have any common characters, then return the sum of the lengths of the two strings. 
Input Format:
The first only line of input contains a string, that denotes the value of string S. The following line contains a string, that denotes the value of string T.
Output Format:
Length of the smallest super-sequence of given two strings. 
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
ab
ac
Sample Output 1 :
3
Explanation of Sample Output 1 :
Their smallest super sequence can be "abc" which has length = 3.
Sample Input 2 :
pqqrpt
qerepct
Sample Output 2 :
9

*/
#include<bits/stdc++.h>
using namespace std;
int helper(char str1[], int len1, char str2[], int len2,int **dp){
	if(len1==0){
		return len2;
	}
	if(len2==0){
		return len1;
	}
	if(dp[len1][len2]>=0){
		return dp[len1][len2];
	}
	int ans;
	if(str1[0] == str2[0]){
		ans = 1+helper(str1+1,len1-1,str2+1, len2-1, dp);
	} 
	else{
		int option1 = helper(str1,len1,str2+1, len2-1, dp);
		int option2 = helper(str1+1,len1-1,str2, len2, dp);
		ans = 1 +min(option1, option2);
	}
	dp[len1][len2] = ans;
	return ans;
}

int smallestSuperSequence(string str1, string str2){
	int len1 = str1.length();
	int len2 = str2.length();
	int **dp = new int *[len1+1];
	for(int i=0;i<len1+1;i++){
		dp[i] = new int [len2+1];
		for(int j=0;j<len2+1;j++){
			dp[i][j] =-1;
		}
	}
	int ans = helper(str1, len1, str2, len2, dp);
	for(int i=0;i<len1+1;i++){
		delete[] dp[i];
	}
	delete [] dp;
	return ans;
}

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << smallestSuperSequence(str1, str2);
    return 0;
}
