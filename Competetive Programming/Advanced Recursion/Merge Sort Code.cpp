/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 

*/

#include <iostream>
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

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
