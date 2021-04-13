#include<bits/stdc++.h>
using namespace std;


int findDuplicate(vector<int>& nums) {
    for(int i=0 ; i<nums.size() ; i++)
    {
        while(nums[i]!=i+1)    
        {
        	if(nums[i]==nums[nums[i]-1])     
                return nums[i];
            else
                swap(nums[i],nums[nums[i]-1]);
        }
    }
    return -1;
}


int main(){
	int n;
	cin>>n;
	vector<int> nums;
	for(int i=0;i<n;i++){
		int x;
		cin>>n;
		nums.push_back(x);
	}
	
	cout<<findDuplicate(nums);
}
