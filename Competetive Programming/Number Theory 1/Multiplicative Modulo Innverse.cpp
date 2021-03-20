/*
Mutiplicative Modulo inverse

(A.B)mod m = 1
if A and m are given we need to find B
*/

/*
Theory


ax + by = gcd(a,b)
x1,y1 <-  gcd(b,a%b)

bx1 + (a%b)y1

x = y1
y = x1 - (a/b)y1

we need to find gcd, x1, y1;


*/

#include<bits/stdc++.h>
using namespace std;

class Triplet {
	public:
		int x;
		int y;
		int gcd;
};
Triplet extendedEuclid(int a,int b){
	//Extended Euclid Algorithm
	if(b==0){
		Triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}
	Triplet smallAns = extendedEuclid(b, a%b);
	Triplet ans;
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.y;
	ans.y = smallAns.x - (a/b)*smallAns.y;
	return ans;
}
int mmInverse(int a,int  m){
	Triplet ans = extendedEuclid(a,m);
	return ans.x;
}
int main(){
	int a, m;
	cin>>a>>m;
	int ans = mmInverse(a,m);
	cout<<"Multiplicative Modulo Inverse "<<ans<<endl;
	return 0;
}


