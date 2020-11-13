#include<bits/stdc++.h>
using namespace std;

bool isTriplet(int arr[], int n, int sum){
	int l,r;
	sort(arr,arr+n);
	
	for(int i=0;i<n-2;i++){
		l=i+1;
		r= n-1;
		while(l<r){
			if(arr[i] + arr[l] + arr[r] == sum ){
				return true;
			}
			else if(arr[i] + arr[l] + arr[r] < sum ){
				l++;
			}
			else{
				r--;
			}
			
		}
	}
	return false;
}
bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++) 
    {
 
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++) 
        {
            if (s.find(curr_sum - A[j]) != s.end()) 
            {
                return true;
            }
            s.insert(A[j]);
        }
    }
 
    return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	
	int n,sum;
	cin>>n>>sum;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<find3Numbers(arr,n,sum)<<endl;
	}
}
