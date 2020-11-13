#include<iostream>
using namespace std;
int max_water(int arr[], int n){
	int size = n-1;
	int prev =arr[0];
	int prev_index = 0;
	int water = 0;
	int temp = 0;
	for(int i=1;i<=size;i++){
		if(arr[i] >= prev){
			prev = arr[i];
			prev_index = i;
			temp = 0;
		}
		else{
			water+= prev - arr[i];
			temp += prev - arr[i];
		}
	}
	if(prev_index < size){
		water -=temp;
		prev =arr[size];
		
		for(int i=size;i>=prev_index;i--){
			if(arr[i]>=prev){
				prev = arr[i];
			}
			else{
				water += prev - arr[i];
			}
		}
	}
	return water;
	
	
}


int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Maximum Water : "<<max_water(arr,n);
	delete [] arr;
}
