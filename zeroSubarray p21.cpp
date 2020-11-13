#include <bits/stdc++.h>
using namespace std;
bool findZeroSum(int arr[],int n){
    unordered_set<int> sumSet;
    int sum = 0;
    for(int i=0;i<n;i++){
		sum+= arr[i];
		        if(sum == 0 || sumSet.find(sum) != sumSet.end()){
		            return true;
		            
		        }
		        sumSet.insert(sum);
		    
	        }
	        return false;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
	        cin>>arr[i];
         }
         if(findZeroSum(arr,n)){
             cout<<"Yes"<<endl;
         }
         else{
             cout<<"No"<<endl;
         }
	        
    }
 	return 0;
}
