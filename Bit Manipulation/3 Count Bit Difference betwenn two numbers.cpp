#include<bits/stdc++.h>
using namespace std;
int bitDifference(int a, int b){
	int n= a^b;
	int count = 0;
	while(n){
		n = n & (n-1);
		count++;
	}
	return count;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<bitDifference(a,b);
}
