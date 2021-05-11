#include<bits/stdc++.h>
using namespace std;

int trapping_water(int *arr, int n){
	int *left_max = new int[n];
    int *right_max = new int[n];
    
    left_max[0] = arr[0];
    for(int i=1;i<n;i++){
        left_max[i] = max(left_max[i-1], arr[i]);
    }
    
    right_max[n-1] = arr[n-1];
    
    for(int i=n-2;i>=0;i--){
        right_max[i] = max(right_max[i+1], arr[i]);
        
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += min(left_max[i],right_max[i]) - arr[i];
    }
    return sum;
}

int trapping_water1(int *arr, int n){
	int left = 0,right = n-1;
	int res = 0 ;
	int maxleft = 0;
	int maxright = 0;
	while(left<=right){
		if(arr[left] <= arr[right]){
			if(arr[left]>=maxleft){
				maxleft = arr[left];
			}
			else{
				res+= maxleft - arr[left];
			}
			left++;
		}
		else{
			if(arr[right]>=maxright){
				maxright = arr[right];
			}
			else{
				res+= maxright - arr[right];
			}
			right--;
			
		}
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	
	cout<<trapping_water1(arr, n);
	
}
