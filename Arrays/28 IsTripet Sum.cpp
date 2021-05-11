#include<bits/stdc++.h>
using namespace std;

int isTriplet(int *arr, int n, int sum){
	int l,r;
	sort(arr, arr+n);
	for( int i=0;i<n-2;i++){
		l = i+1;
		r= n-1;
		while(l<r){
			if(arr[i] + arr[l] + arr[r] == sum){
				return true;
			}
			else if(arr[i] + arr[l] + arr[r] < sum){
				l++;
			}
			else{
				r--;
			}
		}
	}
	return false;
}
int main(){
	int n,k;
	cin>>n>>k;
	int * arr= new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<isTriplet(arr, n, k);
}
