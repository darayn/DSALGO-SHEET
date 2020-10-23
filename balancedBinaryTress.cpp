#include<bits/stdc++.h>

using namespace std;


int balancedBTs(int h){

	if(h==0 || h==1){
		return 1;
	}

	int m = pow(10,9) + 7;
	int x = balancedBTs(h-1);
	int y = balancedBTs(h-2);

	long res1 = (long)x*x;//typecasting to long is used to answer in range 
	long res2 = (long)x*y*2;

	int ans1 = (int)(res1%m);//again to retypecast it in int
	int ans2 = (int)(res2%m);

	int ans = (ans1+ans2)%m;

	return ans;
}

int main(){

	int h;
	cin>>h;
	cout << balancedBTs(h) << endl;
	return 0;
}
