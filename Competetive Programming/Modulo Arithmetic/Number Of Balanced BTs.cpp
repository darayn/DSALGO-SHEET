/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315

*/

#include <iostream>
using namespace std;
typedef long long ll;
ll m = 1000000000 + 7;
int balancedBTs(int h) {
	if(h==0||h==1){
        return 1;
    }
    ll x=balancedBTs(h-1);
    ll y=balancedBTs(h-2);
    ll ans = (x*x) + 2*(x*y);
    return ans%m;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
