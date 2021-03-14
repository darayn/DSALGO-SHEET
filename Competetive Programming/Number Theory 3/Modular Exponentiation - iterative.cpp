#include<bits/stdc++.h>
using namespace std;

int modExo_iter(int a, int b, int c){
	int ans = 1;
	while(b!=1){
		if(b&1 == 1){
			ans = (ans * a)%c;
		}
		
		a=(a * a)%c;
		b/=2;
	}
	return ans;
}


int main(){
	int a = 2;
	int b = 11;
	int c = 5;
	cout<<modExo_iter(a,b,c);
}


