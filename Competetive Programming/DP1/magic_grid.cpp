/*
You are given a magic grid A with R rows and C columns. In the cells of the grid, you will either get magic juice, which increases your strength by |A[i][j]| points, or poison, which takes away |A[i][j]| strength points. If at any point of the journey, the strength points become less than or equal to zero, then you will die.
You have to start from the top-left corner cell (1,1) and reach at the bottom-right corner cell (R,C). From a cell (i,j), you can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and you can not move outside the magic grid. You have to find the minimum number of strength points with which you will be able to reach the destination cell.
Input format:
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with A[i][j] < 0 contain poison, others contain magic juice.
Output format:
Output T lines, one for each case containing the minimum strength you should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).
Constraints:
1 = T = 5
2 = R, C = 500
-10^3 = A[i][j] = 10^3
A[1][1] = A[R][C] = 0
Time Limit: 1 second
Sample Input 1:
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0
Sample Output 1:
2
1
2

*/

#include<bits/stdc++.h>
using namespace std;
int strength(int **arr, int r, int c){
	int **temp = new int * [r];
	for(int i=0;i<r;i++){
		temp[i] = new int[c]();
	}
	temp[r-1][c-1] = 1;
	temp[r-2][c-1] = 1;
	temp[r-1][c-2] = 1;
	for(int i = c-3;i>=0;i--){
		if(arr[r-1][i+1] < 0){
			temp[r-1][i] = temp[r-1][i+1] - arr[r-1][i+1];
		}
		else{
			temp[r-1][i] = max(1,temp[r-1][i+1] - arr[r-1][i+1]);
		}
	}
	for(int i = r-3;i>=0;i--){
		if(arr[i+1][c-1] < 0){
			temp[i][c-1] = temp[i+1][c-1] - arr[i+1][c-1];
		}
		else{
			temp[i][c-1] = max(1,temp[i+1][c-1] - arr[i+1][c-1]);
		}
	}
	for(int i=r-2;i>=0;i--){
		for(int j=c-2;j>=0;j--){
			int down;
			int right;
			if(arr[i+1][j]<0){
				down = temp[i+1][j] - arr[i+1][j];
			}
			else{
				down = max(1, temp[i+1][j] - arr[i+1][j]);
			}
			if(arr[i][j+1]<0){
				right = temp[i][j+1] - arr[i][j+1];
			}
			else{
				right = max(1,temp[i][j+1] - arr[i][j+1]);
			}
			temp[i][j] = min(down, right);
			
		}
	}
	int ans = temp[0][0];
	for(int i=0;i<r;i++){
		delete [] temp[i];
	}
	delete [] temp;
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		int **arr = new int *[r];
		for(int i =0;i< r;i++){
			arr[i] = new int [c];
			for(int j=0;j<c;j++){
				cin>>arr[i][j];
			}
		}
		cout<<strength(arr, r, c);
	}
}
