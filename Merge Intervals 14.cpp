#include<bits/stdc++.h>
using namespace std;
struct Interval {
	int start;
	int end;
	
};
bool mycomp(Interval a, Interval b)  
{ 
	return a.start < b.start; 
}  

void merge(Interval arr[], int n)
{
	sort(arr,arr+n, mycomp);
	
	int index = 0;
	for(int i=1;i<n;i++){
		if(arr[index].end >= arr[i].start){
			arr[index].end = max(arr[index].end, arr[i].end);
			arr[index].start = min(arr[index].start, arr[i].start);    
		}
		else{
			index++;
			arr[index] = arr[i];
		}
	}
	
	cout<<"\n The Merged Intervals are: ";
	for(int i=0;i<=index;i++){
		cout << "[" << arr[i].start << ", " << arr[i].end << "] ";  
	}
}

int main(){
	int n;
	cin>>n;
	Interval Int[n];
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		Int[i].start = x;
		Int[i].end  =y;
	}
	merge(Int,n);
}
