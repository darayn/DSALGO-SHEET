#include<bits/stdc++.h>
using namespace std;


int setBits(int N) {
        int count =0;
        while(N){
            // count++;
            // N = N & (N-1);
             if(N & 1){
                 count++;
            }
            N = N >> 1;
        }
        return count;
}
int main(){
	int n;
	cout<<"Enter the Number for counting setbits"<<endl;
	cin>>n;
	cout<<setBits(n);
}
