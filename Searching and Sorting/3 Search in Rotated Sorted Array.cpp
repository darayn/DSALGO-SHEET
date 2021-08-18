#include <bits/stdc++.h>
using namespace std;
 
int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;
 
    int mid = (l + h) / 2;
    if (arr[mid] == key){
    	return mid;
	}
        
 
    if (arr[l] <= arr[mid]) {
        if (key >= arr[l] && key <= arr[mid])
        {
        	return search(arr, l, mid - 1, key);
		}
        return search(arr, mid + 1, h, key);
    }
 
    /* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
    must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid + 1, h, key);
 
    return search(arr, l, mid - 1, key);
}
 
int main()
{
    
    int n , target;
    cin>>n>>target;
   	int *arr = new int[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
	}
    int i = search(arr, 0, n - 1, target);
 
    if (i != -1)
        cout << "Index: " << i << endl;
    else
        cout << "Key not found";
}

