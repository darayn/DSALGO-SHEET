#include<bits/stdc++.h>
using namespace std;
int min(int x,int y){
	if(x<y){
		return x;
	}
	return y;
}
int max(int x,int y){
	if(x<y){
		return y;
	}
	return x;
}
long long longest_subsequence(int arr[],int n){
	set<int> hashSet;
	for(int i=0;i<n;i++){
		hashSet.insert(arr[i]);
	}
	int longestStreak = 0;
	for(int i=0;i<n;i++){
		if(!hashSet.count(arr[i]-1)){
			
		
			int currentNum =arr[i];
			int curren_streak = 1;
			
			while(hashSet.count(currentNum + 1)){
				currentNum++;
				curren_streak++;
			}
			longestStreak = max(longestStreak ,curren_streak);
		}
		
	}
	return longestStreak;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
		cin>>arr[i];
		}
		cout<<longest_subsequence(arr,n)<<endl;
        
    }
 	return 0;
}

