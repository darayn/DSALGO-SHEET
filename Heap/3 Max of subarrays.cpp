#include<bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(vector<int> arr, int n, int k){
	priority_queue<int> heap;
	priority_queue<int> drop;
	vector<int> result;
	int i=0;
	for(i=0;i<k;i++){
		heap.push(arr[i]);
	}
	result.push_back(heap.top());
	for(i=k;i<n;i++){
		if(arr[i-k] == heap.top()){
			heap.pop();
		}
		else{
			drop.push(arr[i-k]);
		}
		
		while(!drop.empty() && drop.top()==heap.top()){
			heap.pop();
			drop.pop();
		}
		heap.push(arr[i]);
		
		result.push_back(heap.top());
	}
	return result;
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> nums,res;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		nums.push_back(x);
	}
	
	res = max_of_subarrays(nums, n, k);
	
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
}
