#include<bits/stdc++.h>
using namespace std;
long long min(long long int x,long long int y){
	if(x<y){
		return x;
	}
	return y;
}
long long max(long long int x,long long int y){
	if(x<y){
		return y;
	}
	return x;
}
long long max_product(int arr[],int n){
	long long int max_ending_here = 1;
	long long int min_ending_here = 1;
	long long int max_so_far = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>0){
			max_ending_here = max_ending_here *arr[i];
			
			min_ending_here = min(min_ending_here*arr[i],1);
		}
	    else if(arr[i] ==0){
	    	max_ending_here = 1;
	    	min_ending_here = 0;
		}
		else{
			long long int temp = max_ending_here;
			max_ending_here = max(min_ending_here*arr[i],1);
			min_ending_here = temp *arr[i];
			
		}
		max_so_far = max(max_ending_here,max_so_far);
	}
	return max_so_far;
}

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
		cout<<max_product(arr,n)<<endl;
        
    }
 	return 0;
}

