#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int max_sum = arr[0];
	    for(int i=1;i<n;i++){
	        arr[i] = max(arr[i] + arr[i-1],arr[i]);
	        if(arr[i] > max_sum){
	            max_sum = arr[i];
	        }
	    }
	    cout<<max_sum <<endl;
	    
	}
	return 0;
}
