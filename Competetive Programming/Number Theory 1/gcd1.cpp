#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll gcd(ll x, ll y)
{
    if(x<y)
    {
        return gcd(y, x);
    }
    if(y==0)
    {
        return x;
    }
    return gcd(y, x%y);   
}
int main(){
	ll x, y;
	cin>>x>>y;
	cout<<gcd(x,y);
}
