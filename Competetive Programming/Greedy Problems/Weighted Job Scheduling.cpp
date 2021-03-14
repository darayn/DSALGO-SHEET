/*
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 = N = 10^6
1 = ai, di, p = 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250

*/

#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
    	int start,finish,profit;
    
};
bool sorter(Job j1,Job j2){
    return (j1.finish < j2.finish);
}

int binary_search(Job jobs[], int index){
    int low = 0;
    int high = index - 1;
    while(low<=high){
        int mid = (low + high) / 2;
        if(jobs[mid].finish <= jobs[index].start){
            
            if(jobs[mid+1].finish <= jobs[index].start){
            	low = mid + 1;
                
			}
            else{
                return mid;
            } 
		}
        else{
            high = mid-1;
        }
        
    }
    return -1;
}

int max_profit(Job arr[], int n){
    int *table = new int[n];
    table[0] = arr[0].profit;
    
    for(int i=1;i<n;i++){
        int inclProfit = arr[i].profit;
        int l = binary_search(arr,i);
        if(l!= -1){
            inclProfit += table[l];
        }
        
        table[i] = max(inclProfit,table[i-1]);
    }
    int result = table[n-1];
    delete[] table;
    return result;
}

int main()
{
    int n;
    cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }
    sort(arr,arr+n,sorter);
    cout<<max_profit(arr,n)<<endl;
    return 0;
}
