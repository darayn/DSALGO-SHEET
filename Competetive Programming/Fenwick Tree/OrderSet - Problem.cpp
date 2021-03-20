/*
In this problem, you have to maintain a dynamic set of numbers which support the two fundamental operations
INSERT(S,x): if x is not in S, insert x into S
DELETE(S,x): if x is in S, delete x from S
and the two type of queries
K-TH(S) : return the k-th smallest element of S
COUNT(S,x): return the number of elements of S smaller than x
Input Format
Line 1: Q (1 = Q = 200000), the number of operations
In the next Q lines, the first token of each line is a character I, D, K or C meaning that the corresponding operation is INSERT, DELETE, K-TH or COUNT, respectively, following by a whitespace and an integer which is the parameter for that operation.

If the parameter is a value x, it is guaranteed that = |x| = 10^9. If the parameter is an index k, it is guaranteed that 1 = k = 10^9.`
Output
For each query, print the corresponding result in a single line. In particular, for the queries K-TH, if k is larger than the number of elements in S, print the word 'invalid'.
Input Format
8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2
Output Format
1
2
2
invalid

*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
pair<long long int,long long int> M[MAX], T[MAX];
int BIT[MAX],A[MAX];
char C[MAX];
int n;
bool b;
int get_count(int index){
	if(index == 0){
		return 0;
	}
	long long int sum = 0;
	while(index > 0){
		sum+= BIT[index];
		index -= index & (-index);
	}
	return sum;
}
void updateBIT(int index, int val){
	while(index < MAX){
		BIT[index] += val;
		index += index & (-index);
	}
}
int b_search(int x){
	int low = 0, high = n-1, mid, ans = -1;
	while(low <= high){
		mid = (low + high) >> 1;
		if(M[mid].first == x){
			b=1;
			return mid;
		}
		else if(M[mid].first > x){
			high = mid - 1;
		}
		else{
			ans = mid;
			low = mid + 1;
		}
	}
	b=0;
	return ans;
}
int main(){
	int Q;
	cin>>Q;
	
	int k=0;
	for(int i = 0;i < Q;i++){
		C[i] = getchar();
		while(C[i] < 65 || C[i] >= 91){
			C[i] = getchar();
		}
		cin>>A[i];
		if(C[i] == 'I'){
			T[k].first = A[i];
			T[k++].second = 0;
		}
	}
	sort(T, T+k);
	M[0] = T[0];
	n=1;
	for(int i=1;i<k;i++){
		if(T[i].first != T[i-1].first){
			M[n++] = T[i];
		}
	}
	for(int i=0;i<Q;i++){
		if(C[i] == 'I'){
			int x = b_search(A[i]);
			if(M[x].second == 0){
				M[x].second = 1;
				updateBIT(x+1, 1);
			}
		}
		else if(C[i] == 'D'){
			int x = b_search(A[i]);
			if(x!= -1 && M[x].second == 1 && b){
				updateBIT(x+1,-1);
				M[x].second = 0;
			}
		}
		else if(C[i] == 'C'){
			int x = b_search(A[i]);
			if(b){
				cout<<get_count(x+1 - 1)<<endl;
			}
			else if(x!= -1){
				cout<<get_count(x+1)<<endl;
			}
			else{
				cout<<"0"<<endl;
			}
		}
		else if(C[i] == 'K'){
			k = A[i];
			int x =-1;
			int low = 1;
			int high = MAX - 1,mid;
			bool mno = 0;
			while(low <= high){
				mid = (low + high) >> 1;
				if(get_count(mid)==k && get_count(mid -1)!= k){
					mno = 1;
					x =mid;
					break;
				}
				else if(get_count(mid)<k){
					x = mid;
					low = mid + 1;
				}
				else{
					high = mid - 1;
				}
			}
			if(!mno){
				cout<<"invalid"<<endl;
			}
			else{
				cout<<M[x-1].first<<endl;
			}
		}
	}
	return 0;
}





