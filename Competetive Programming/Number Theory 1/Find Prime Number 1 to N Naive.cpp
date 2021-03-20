#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
	
	int count = 0;
	for(int j=1;j<=sqrt(n);j++){
		if(n%j == 0){
			if( j * j == n){
				count++;
			}
			else{
				count+=2;
			}
		}
	}
	if(count==2){
		return true;
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	int count = 0;
	for(int i=1;i<=n;i++){
		if(isPrime(i)){
			count++;
		}
	}
	cout<<count<<endl;
}
