#include <bits/stdc++.h>

using namespace std;

long long merge(long long *arr,int left, int mid,int right){
    int i=left;
    int j=mid;
    int k=0;
    int temp[right-left+1];
    long long count = 0;
    while(i<mid &&j<=right){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
            
        }
        else{
            temp[k++] = arr[j++];
            count += mid-i;
        }
    }
    while(i<mid){
        temp[k++] = arr[i++];
        
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(int i=left,k=0;i<=right;i++,k++){
        arr[i] = temp[k];
    }
    return count;
}
long long merge_sort(long long *arr,int left, int right){
    long long count =0;
    if(right>left){
        int mid = (left + right) /2;
        long long countLeft = merge_sort(arr,left,mid);
        long long countRight = merge_sort(arr, mid+1, right);
        long long countMerge = merge(arr,left,mid+1,right);
        
        return countLeft+countRight+countMerge;
        
    }
    return count;
    
}
long long getInversions(long long *arr, int n)
{
   long long ans = merge_sort(arr,0,n-1);
   return ans;
    
}
int main(){
	int n;
	cin>>n;
	long long arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Total No of Inversions are:"<<getInversions(arr,n)<<endl;
}
