#include<bits/stdc++.h>
using namespace std;
struct ElementCount{
	int e,c;
};


void moreThan_k2(int *arr, int n, int k){
	int x = n / k;
	unordered_map<int, int> freq;
	for(int i=0;i<n;i++){
		freq[arr[i]]++;
	}	
	for(auto i:freq){
		if(i.second > x){
			cout<<i.first<<endl;
		}
	}
}

void moreThan_k1(int *arr, int n, int k){
	if(k<2){
		return;
	}
	
	struct ElementCount temp[k-1];
	
	for(int i=0;i<k-1;i++){
		temp[i].c = 0;
	}
	for(int i=0;i<n;i++){
		int j;
		for(j=0;j<k-1;j++){
			if(temp[j].e = arr[i]){
				temp[j].c +=1;
				break;
			}
		}
		if(k==k-1){
			int l;
			for(l=0;l<k-1;l++){
				if(temp[l].c == 0){
					temp[l].e = arr[i];
					temp[l].c ++;
					break;
				}
			}
			
			if(l==k-1){
				for(l=0;l<k;l++){
					temp[l].c-=1;
				}
			}
		}
		
	}
	
	for (int i = 0; i < k - 1; i++)
    {        
        int ac = 0;
        for (int j = 0; j < n; j++){
        	if (arr[j] == temp[i].e){
            	ac++;
			}
		}
            
        if (ac > n / k){
        	cout << "Number:" << temp[i].e
                 << " Count:" << ac << endl;
		}
            
    }
}
int main(){
	int n,k;
	cin>>n>>k;
	int *arr = new int[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
		
	}
	moreThan_k1(arr,n,k);
	return 0;
	
	
}
 
 
 

