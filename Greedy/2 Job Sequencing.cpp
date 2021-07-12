#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


bool comparator(Job a, Job b){
    return a.profit > b.profit;
}
    int max(int a, int b){
    if(a>b){
		return a;
	}
	return b;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr, arr + n, comparator);
    int max_deadline = arr[0].dead;
    for(int i=1;i<n;i++){
        max_deadline = max(arr[i].dead,max_deadline);
    }
    
    int *d = new int[max_deadline+1];
    for(int i=0;i<=max_deadline;i++){
        d[i] = -1;
    }
    int countJobs = 0;
    int profit = 0;
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>0;j--){
            if(d[j] == -1){
                d[j] = i;
                countJobs++;
                profit+=arr[i].profit;
                break;
            }
            
        }
    }
    vector<int> ans;
    ans.push_back(countJobs);
    ans.push_back(profit);
    return ans;
} 

int main() 
{ 

    int n;
    
    //size of array
    cin >> n;
    Job arr[n];
    
    for(int i = 0;i<n;i++){
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
    }
   
    vector<int> ans = JobScheduling(arr, n);
    cout<<ans[0]<<" "<<ans[1]<<endl;

	return 0; 
}

