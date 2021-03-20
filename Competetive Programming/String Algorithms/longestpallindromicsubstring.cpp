#include<bits/stdc++.h>
using namespace std;
int longest_pallindrome(string s){
	int n= s.length();
	int max = 0;
	for(int i=0;i<n;i++){
		//odd length
		int l=i,r=i;
		while(l>=0 && r<n && s[l] == s[r]){
			int curr_len = r-l+1;
			if(curr_len > max){
				max = curr_len;
			}
			l--;
			r++;
		}
		// even length
		l = i;
		r = i+1;
		while(l>=0 && r<n && s[l] == s[r]){
			int curr_len = r-l+1;
			if(curr_len > max){
				max = curr_len;
			}
			l--;
			r++;
		}
		
	
	}
	return max;
}

int main(){
	string str;
	cin>>str;
	
	
	cout<<longest_pallindrome(str);
	
}
