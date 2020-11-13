#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int arr1[m], arr2[n];
        for(int i=0;i<m;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        sort(arr1,arr1+m);
        sort(arr2,arr2+n);
        int count =0;
        
        int i=0,j=0;
        while(i<m && j<n){
            if(arr1[i] == arr2[j]){
                i++;
                j++;
                count++;
            }
            else if(arr1[i] > arr2[j]){
                j++;
            }
            else if(arr1[i] < arr2[j]){
                i++;
            }
        }
        
        if(count==n){
            cout<<"Yes"<<endl;
        }
        else{
             cout<<"No"<<endl;
        }
        
    }
	return 0;
}
