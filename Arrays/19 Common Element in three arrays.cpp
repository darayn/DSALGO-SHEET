#include<bits/stdc++.h>
using namespace std;

void common_elements(int *arr1, int *arr2, int *arr3, int p, int q, int r){ 

	set<int> s;
	for(int i=0;i<p;i++){
		s.insert(arr1[i]);
	}
	set<int> sp;
	for(int i=0;i<q;i++){
		sp.insert(arr2[i]);
	}
	
	for(int i=0;i<r;i++){
		if(s.find(arr3[i]) != s.end() && sp.find(arr3[i]) != sp.end() ){
			cout<<arr3[i]<<" ";
		}
	}
}
void common_elements2(int *arr1, int *arr2, int *arr3, int p, int q, int r){ 

	int i=0,j=0,k=0;
	while(i<p && j<q && k<r){
		if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
			cout<<arr1[i]<<" ";
			i++;
			j++;
			k++;
		}
		else if(arr1[i] < arr2[j]){
			i++;
		}
		else if(arr2[j] < arr3[k]){
			j++;
		}
		else{
			k++;
		}
	}
}


int main(){
	int p,q,r;
	cin>>p>>q>>r;
	int *arr1 = new int[p];
	int *arr2 = new int[q];
	int *arr3 = new int[r];
	
	for(int i=0;i<p;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<q;i++){
		cin>>arr2[i];
	}
	for(int i=0;i<r;i++){
		cin>>arr3[i];
	}
	common_elements2(arr1,arr2,arr3,p,q,r);
}
