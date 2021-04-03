#include<bits/stdc++.h>
using namespace std;

int minJumps(int *arr, int n){
	int *jump = new int[n];
	if(n==0||arr[0] ==0){
		return INT_MAX;
	}	
	jump[0] = 0;
	
	for(int i=1;i<n;i++){
		jump[i] = INT_MAX;
		for(int j=0;j<i;j++){
			if(i <= j+ arr[j] && jump[j]!=INT_MAX){
				jump[i] = min(jump[i], jump[j] + 1);
			}
		}
	}
	return jump[n-1];
}


int minJumps1(int *arr, int n){
	if(n<=1){
		return 0;
	}
	if(arr[0] == 0){
		return -1;
	}
	int maxReach = arr[0];
	int step = arr[0];
	int jump = 1;
	for(int i=1;i<n;i++){
		if(i==n-1){
			return jump;
		}
		maxReach = max(maxReach,i+arr[i]);
		step--;
		
		if(step == 0){
			jump++;
			if(i>=maxReach){
				return -1;
			}
			step = maxReach-i;
		}
		
	}
	return -1;
}
int main(){
	
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<minJumps(arr,n)<<endl;
	cout<<minJumps1(arr,n);
}
