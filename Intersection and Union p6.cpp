#include <iostream>
using namespace std;
void printUnion(int arr1[],int arr2[],int m,int n){
	int i=0,j=0;
	while(i<n && j<m){
		if(arr1[i] < arr2[j]){
			cout<< arr1[i++]<<" ";
		}
		else if(arr2[j]<arr1[i]){
			cout<<arr2[j++]<<" ";
		}
		else{
			cout<<arr2[j++]<<" ";
			i++;
		}
	}
	while(i<n){
		cout<<arr1[i++]<<" ";
	}
	while(j<m){
		cout<<arr2[j++]<<" ";
	}
}

void printIntersection(int arr1[],int arr2[],int m,int n){
	int i=0,j=0;
	while(i<m && j<n){
		if(arr1[i] < arr2[j]){
			i++;
		}
		else if(arr2[j]<arr1[i]){
			j++;
		}
		else{
			cout<<arr2[j]<<" ";
			i++;
			j++;
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	int arr1[n],arr2[m];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<m;i++){
		cin>>arr2[i];
	}
	cout<<"Union"<<endl;
	printUnion(arr1,arr2,m,n);
    cout<<endl;
    cout<<"Intersection"<<endl;
	printIntersection(arr1,arr2,m,n);
}
