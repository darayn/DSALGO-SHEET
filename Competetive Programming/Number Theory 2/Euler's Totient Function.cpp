#include<bits/stdc++.h>
using namespace std;

void eulerPhi(int n){
	int *phi = new int[n+1];
	for(int i=1;i<=n;i++){
		phi[i] = i;
	}
	for(int i=2;i<=n;i++){
		if(i==phi[i]){
			phi[i] = i-1;
			for(int j=i*2;j<=n;j+=i){
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<"Euler totient Phi for "<<i<<" is "<<phi[i]<<endl;
		
	}
	
	 
}

int main(){
	int n;
	cin>>n;
	eulerPhi(n);
}
