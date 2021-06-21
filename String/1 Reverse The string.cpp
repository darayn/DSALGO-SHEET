#include<bits/stdc++.h>
#include<string.h>

using namespace std;
void reverseString(char *s,int n){
	for(int i=1;i<=n/2;i++){
		swap(s[i-1],s[n-i]);
	}
	
}
int main(){
	int n;
	cin>>n;
	
	char s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	reverseString(s,n);
	for(int i=0;i<n;i++){
		cout<<s[i]<<" ";
	}
}
