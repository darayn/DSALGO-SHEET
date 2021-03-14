/*
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
Output Format:
Print the size of maximum square sub-matrix.
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4

*/
#include<bits/stdc++.h>
using namespace std;
int findMaxSquare(int ** arr, int n,int m, int **temp){
	int max_element=0;
	if(arr[0][0] == 0){
		temp[0][0] = 1;
		max_element = 1;
	}
	else{
		temp[0][0] = 0;
	}
	for(int i=1;i<n;i++){
		if(arr[i][0]==0){
			temp[i][0] = 1;
		}
		else{
			temp[i][0] = 0;
		}
		max_element=max(max_element, temp[i][0]);
	}
	for(int i=1;i<m;i++){
		if(arr[0][i]==0){
			temp[0][i] = 1;
		}
		else{
			temp[0][i] = 0;
		}
		max_element=max(max_element,temp[0][i] );
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(arr[i][j] == 1){
				temp[i][j] = 0;
			} 
			else{
				if(temp[i][j-1]>=1 && temp[i-1][j-1]>=1 && temp[i-1][j]>=1){
					temp[i][j]= 1+min(temp[i][j-1],min(temp[i-1][j-1],temp[i-1][j]));
				}
				else{
					temp[i][j]= 1;
				}
			}
			max_element = max(max_element, temp[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		delete [] temp[i];
	}
	delete [] temp;
	return max_element;
	
}
int findMaxSquareWithAllZeros(int ** arr, int n,int m){
	int **temp = new int*[n];
	for(int i=0;i<n;i++){
		temp[i] = new int[m];
		for(int j=0;j<m;j++){
			temp[i][j] = 0;
		}
	}
	return findMaxSquare(arr, n,m ,temp);
}

int main(){
	int n,m;
	cin>>n>>m;
	int ** arr = new int*[n];
	for(int i=0;i<n;i++){
		arr[i] = new int[m];
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	cout<<findMaxSquareWithAllZeros(arr, n, m);
}

