#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int x){
	if(x == 0|| x== 1){
		return x;
	}
	int i=1,result = 1;
	while(result <= x){
		i++;
		result = i*i;
		
	}
	return i-1;
}
// Solution using binary ssearch

int floorSqrt_binary_search(int x){
	if(x == 0|| x== 1){
		return x;
	}
	int start = 1, end = x, ans;
	
	while(start<= end){
		int mid = (start + end) / 2;
		if(mid*mid == x){
			return mid;
		}
		if(mid <= x/mid){
			start = mid + 1;
			ans = mid;
		}
		else{
			end = mid - 1;
		}
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<floorSqrt(n)<<endl;
	cout<<floorSqrt_binary_search(n);
}
