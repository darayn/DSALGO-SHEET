/*
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 = i = j = n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
Input Format
Line 1: n (1 = n = 30000).

Line 2: n numbers a1, a2, ..., an (1 = ai = 10^9).

Line 3: q (1 = q = 200000), the number of k- queries.

In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 = i = j = n, 1 = k = 10^9).
Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
Sample Output
2
0
3 

*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 30001
int BIT[30009];
void update(int pos){
	while(pos<=MAX){
		BIT[pos] +=1;
		pos += (pos&-pos);
	}
}
int query(int pos){
	int result = 0;
	while(pos){
		result += BIT[pos];
		pos-= (pos & -pos);
	}
	return result;
}
class data{
	public:
		int element, index;
};
class query_data{
	public:
		int i, j, k, query_index;
};
bool compare(data a,data b){
	return a.element > b.element;
}
bool cmp(query_data a, query_data b){
	return a.k>b.k;
}
int main(){
	int n;
	cin>>n;
	data arr[n+9];
	for(int i=0;i<n;i++){
		cin>>arr[i].element;
		arr[i].index = i+1;
	}
	sort(arr, arr+n, compare);
	int q_no;
	cin>>q_no;
	query_data q[q_no];
	for(int i=0;i<q_no;i++){
		cin>>q[i].i>>q[i].j>>q[i].k;
		q[i].query_index = i;
	}
	int ans[q_no];
	sort(q,q+q_no,cmp);
	int pos = 0;
	for(int i=0;i<q_no;i++){
		while(pos < n && arr[pos].element>q[i].k){
			update(arr[pos].index);
			pos++;
		}
		ans[q[i].query_index] = query(q[i].j) - query(q[i].i - 1);
	}
	for(int i=0;i<q_no;i++){
		cout<<ans[i]<<"\n";
	}
}
// use second approach also

