#include<bits/stdc++.h>
using namespace std;

int modExo(int a,int b, int c){
	if(a==0){
		return 0;
	}
	if(b==0){
		return 1;
	}
	long ans;
	if(b%2 == 0){
//		b is even
		long smallAns = modExo(a,b/2,c);
		ans = (smallAns * smallAns)%c;
	}
	else{
		long smallAns = modExo(a, b-1,c);
		ans = (a%c);
		ans = (ans*smallAns)%c;
	}
	
	return int((ans+c)%c);
	
}
int main(){
	int a = 2;
	int b = 11;
	int c = 5;
	cout<<modExo(a,b,c);
}
