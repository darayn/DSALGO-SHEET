/*
Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
Input
First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.
Output
For each test case print the required answer in a seperate line.
Sample Input:
2
3 2 
3 1 4
4 1
3 2 3 9
Sample Output:
3
9

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll k,ll arr[],ll n,ll mid){
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum+= arr[i]/mid;
        if(sum>= k){
            return true;
        }
        
    }
    return false;
}

ll max_candies(ll arr[],ll n,ll k){
    sort(arr,arr+n);
        ll start= 0;
        ll end =arr[n-1];
        ll mid = 0;
        while(start<end){
        	mid =( start +end) /2;
            if(check(k,arr,n,mid)){
               
                start =mid;
            }
            else{
                end = mid;
            }
            if(end-start==1)
			{
                if(check(  k,arr,n, end))
                {
                    
                    return end;
				}
                else
                {
                    return start;
                }
			}
        }
    return mid;
}

int main() {
	ll t;
    cin>>t;
    while(t--){
        ll n;
        ll k;
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        
        cout<<max_candies(arr,n,k)<<endl;
    }
}
