#include<bits/stdc++.h>
using namespace std;


vector<int> pairSum(vector<int> arr, int n, int sum){
//	
	unordered_set<int> s;
	vector<int> result;
	for(int i=0;i<arr.size(); i++){
		int x = sum-arr[i];
		if(s.find(x)!=s.end()){
			result.push_back(x);
			result.push_back(arr[i]);
			return result;
		}
		s.insert(arr[i]);
	}
	return {};
	
}

int main(){
	int n;
	cin>>n;
	int sum;
	cin>>sum;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	
	auto p = pairSum(arr, n, sum);
	
	if(p.size() == 0){
		cout<<"No Pair Found";
	}
	else{
		cout<<p[0]<<","<<p[1]<<endl;
	}
	return 0;
}
