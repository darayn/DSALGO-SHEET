/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 = N = 10^6
1 = ai, di = 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4

*/
#include<bits/stdc++.h>
using namespace std;
class Activity {
    public:
    	int start;
    	int end;
    
};
bool ActivityCompare(Activity a1,Activity a2){
    return (a1.end<a2.end);
}
int maxActivity(Activity A[], int n){
    int i=0;
    sort(A,A+n,ActivityCompare);
    int count = 1;
    for(int j=1;j<n;j++){
        if(A[j].start >= A[i].end){
            count++;
            i=j;
        }
    }
    return count;
    
}
int main()
{
    int n;
    cin>>n;
    Activity A[n];
    for(int i=0;i<n;i++){
        cin>>A[i].start>>A[i].end;
    }
    cout<<maxActivity(A,n)<<endl;
    return 0;
}
