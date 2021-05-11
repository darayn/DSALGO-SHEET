
#include<bits/stdc++.h>
#include <sstream>
using namespace std;

bool isPallindrome(int N){
    string str ;
    stringstream ss;
    ss<<N;
    ss>>str;
    int len = str.length();
    for(int i=0;i<len/2;i++){
        if(str[i]!= str[len-1-i]){
            return false;
        }
    }
    return true;
}
/*Complete the function below*/
int PalinArray(int a[], int n)
{  
    for(int i=0;i<n;i++){
        bool ans = isPallindrome(a[i]);
        if(ans == false){
            return 0;
        }
    }
    return 1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int* arr = new int[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<PalinArray(arr, n);
	}
}


