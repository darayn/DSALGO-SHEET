#include<bits/stdc++.h>
using namespace std;
void rearrange(int *arr, int n){
	int j=0;
	for(int i=0;i<n;i++){
		if(arr[i]<0){
			if(i!=j){
				swap(arr[i], arr[j]);
			}
			j++;
		}
	}
}

/*
Two Pointer Approach: The idea is to solve this problem with constant space and linear time is by using a two-pointer or two-variable approach where we simply take two variables like left and right which hold the 0 and N-1 indexes. Just need to check that :

Check If the left and right pointer elements are negative then simply increment the left pointer.
Otherwise, if the left element is positive and the right element is negative then simply swap the elements, and Simultaneously increment or decrement the left and right pointers.
Else if the left element is positive and the right element is also positive then simply decrement the right pointer.
Repeat the above 3 steps until the left pointer = right pointer.

*/

void rearrange2pointer(int *arr, int n){
	int left = 0;
	int right = n-1;
	while(left<=right){
		if(arr[left]<0 && arr[right]<0){
			left++;
		}
		else if(arr[left]>0 && arr[right]<0){
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
		else if(arr[left]>0 && arr[right]>0){
			right--;
		}
		else{
			left++;
			right--;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int * arr = new int [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	rearrange2pointer(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
