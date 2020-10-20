#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int left,int mid,int right){
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[right -left + 1];
    while(i<=mid && j<= right){
        if(arr[i] <arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(i = left;i<=right;i++){
        arr[i] = temp[i-left];
    }

}

void merge_sort_algo(int input[], int start,int end){
    
    if(start<end){
        int mid = (start + end) /2;
        merge_sort_algo(input,start,mid);
        merge_sort_algo(input,mid+1,end);
        merge(input,start,mid,end);
       
    }

}
void mergeSort(int input[], int size){
    merge_sort_algo(input,0,size-1);
        
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			
		}
		int k;
		cin>>k;
		mergeSort(arr,n);
		cout<<arr[k-1]<<endl;
	}
	
}


