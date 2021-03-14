#include<bits/stdc++.h>
#define m 100001

using namespace std;
int numofAP(int *arr, int n){
	int ans = n+1;
	unordered_map<int,int>map= new unordered_map<int,int>[n];
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int diff = arr[j] - arr[i];
			map[i][diff]++;
			ans = (ans+1)%m;
		}
	}
	for(int i=n-3;i>=0;i--){
		for(int j=i+1;j<n;j++){
			int diff = arr[j] - arr[i];
			map[i][diff] = (map[i][diff]%m + map[j][diff]%m)%m;
			ans = (ans%m + map[j][diff]%m)%m;
		}
	}
	delete [] map;
	return ans;
}

int main(){
	int n;
	cin>>n;
	int * arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<numofAP(arr, n);
	
}
