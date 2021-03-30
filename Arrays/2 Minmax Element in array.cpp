#include<bits/stdc++.h>
using namespace std;

struct Pair{
	int min,max;
};
struct Pair getMinMax2(int arr[], int low,int high)
{
    struct Pair minmax, mml, mmr;    
    int mid;
     
    if (low == high)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];    
        return minmax;
    }
     
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else
        {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }
     
    mid = (low + high) / 2;
    mml = getMinMax2(arr, low, mid);
    mmr = getMinMax2(arr, mid + 1, high);
     
    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;    
     
    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;    
     
    return minmax;
}
 

struct Pair getMinMax1(int *arr, int n){
	struct Pair minmax;
	int i;
	if(n==1){
		minmax.max = arr[0];
		minmax.min = arr[0];
		return minmax;
	}
	if(arr[0] > arr[1]){
		minmax.max = arr[0];
		minmax.min = arr[1];
	}
	else{
		minmax.min = arr[0];
		minmax.max = arr[1];
	}
	
	for(i=2;i<n;i++){
		if(arr[i]>minmax.max){
			minmax.max = arr[i];
		}
		else if(arr[i]<minmax.min){
			minmax.min = arr[i];
		}
	}
	return minmax;
}
struct Pair getMinMax3(int arr[], int n)
{
    struct Pair minmax;    
    int i;
     
   
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])    
        {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else
        {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }
         
        i = 2;
    }
     
    else
    {
        minmax.min = arr[0];
        minmax.max = arr[0];
         
        i = 1;
    }
    
    while (i < n - 1)
    {        
        if (arr[i] > arr[i + 1])        
        {
            if(arr[i] > minmax.max)    
                minmax.max = arr[i];
                 
            if(arr[i + 1] < minmax.min)        
                minmax.min = arr[i + 1];    
        }
        else       
        {
            if (arr[i + 1] > minmax.max)    
                minmax.max = arr[i + 1];
                 
            if (arr[i] < minmax.min)        
                minmax.min = arr[i];    
        }
        i += 2;
    }        
    return minmax;
}

int main(){
	int n;
	cin>>n;
	int * arr = new int [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	struct Pair minmax1 = getMinMax1(arr,n);
	
	cout << "Minimum element is "<< minmax1.min << endl;
    cout << "Maximum element is "<< minmax1.max<<endl;
    
    struct Pair minmax2 = getMinMax2(arr,0, n-1);
	
	cout << "Minimum element is "<< minmax2.min << endl;
    cout << "Maximum element is "<< minmax2.max<<endl;
    
    struct Pair minmax3 = getMinMax3(arr,n);
	
	cout << "Minimum element is "<< minmax3.min << endl;
    cout << "Maximum element is "<< minmax3.max<<endl;
    return 0;
}
