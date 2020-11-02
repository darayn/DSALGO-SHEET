#include <iostream>
using namespace std;
void print(int arr[],int n){
	for(int i=0;i<n;i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void rearrange(int arr[],int n){
	int j = 0;
	for(int i=0;i<n;i++){
		if(arr[i]<0){
			if(i!=j){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				
			}
			j++;
		}
	}
	print(arr,n);
}
void two_pointer(int arr[],int n){
	int left = 0;
	int right = n-1;
	while(left <= right){
		if(arr[left]<0 && arr[right]<0){
			left++;
		}
		else if(arr[left]>0 && arr[right]<0){
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
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
	print(arr,n);
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	cout<<"1) Partition Approach \n"<<"2) Two Pointer Approach";
	int choice;
	cin>>choice;
	if(choice == 1){
		rearrange(arr,n);
	}
	else{
		two_pointer(arr,n);
	}
}
