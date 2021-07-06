/*
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903

*/
#include<iostream>
#include<algorithm>
using namespace std;

int coins(int n, int *d, int numD, int ** output){
	if(n==0){
		return 1;
	}
	if(numD == 0 || n<0){
		return 0;
	}
	if(output[numD][n] > -1){
		return output[numD][n];
	}
	int first = coins(n-d[0],d,numD, output);
	int second = coins(n, d+1, numD - 1, output);
	output[numD][n] = first + second;
	return first + second;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int amount;
	cin>>amount;
	int ** temp = new int *[n+1];
	for(int i=0;i<n+1;i++){
		temp[i] = new int[amount+1];
		for(int j=0;j<amount+1;j++){
			temp[i][j] = -1;
		}
	}
	cout<<coins(amount, arr, n, temp);
	for (int i = 0; i < n+1; i++)
    {
        delete[] temp[i];
    }
    delete[] temp;
}
