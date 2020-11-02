#include <bits/stdc++.h> 
using namespace std; 

int mini(int x, int y){
	return (x<y) ? x: y;
}
int minJumps(int arr[] , int n){
	int *min_jumps_arr = new int[n];
	if(n==0 || arr[0] == 0){
		return INT_MAX;
	}
	
	min_jumps_arr[0] = 0;
	
	for(int i=1;i<n;i++){
		min_jumps_arr[i] = INT_MAX;
		for(int j = 0;j<i;j++){
			if(i<=j+arr[j] && min_jumps_arr[j]!=INT_MAX){
				min_jumps_arr[i] = mini(min_jumps_arr[i],min_jumps_arr[j] + 1);
				break;
			}
		}
	}
	int ans = min_jumps_arr[n-1];
	delete [] min_jumps_arr;
	return ans;
}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Minimum No of jumps "<<minJumps(arr,n);
}


/*
Video link - https://www.youtube.com/watch?v=jH_5ypQggWg
O(n) Solution - https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
*/
