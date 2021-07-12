#include<bits/stdc++.h>
using namespace std;
int isPallindrome(char S[])
{
    int n = strlen(S);
    for(int i=0;i<=n/2;i++){
        if(S[i] != S[n-i-1]){
            return 0;
        }
    }
    return 1;
}
int main(){
	int n;
	cin>>n;
	char S[n];
	cin>>S;
	if(isPallindrome(S)){
		cout<<S<< " is Pallindrome";
	}
	else{
		cout<<S<< " is not Pallindrome";
	}
}
