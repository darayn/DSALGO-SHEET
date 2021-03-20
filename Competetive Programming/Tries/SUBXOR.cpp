/*
A straightforward question. Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format
First line contains T, the number of test cases. 
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.
Output Format
For each test case, print the required answer.
Constraints:
1 = T = 5
1 = N = 10^5
1 = A[i] = 10^5
1 = K = 10^6
Sample Input
1
5 2
4 1 3 2 7   
Sample Output
3

*/

#include<bits/stdc++.h>
using namespace std;

class trienode {
	public:
		int left_count,right_count;
		trienode * left;
		trienode * right;
		trienode(){
			left_count =0;
			right_count = 0;
			left = NULL;
			right = NULL;
		}
};
int query(trienode *root, int element, int k){
	if(root == NULL){
		return  0;
	}
	int res = 0;
	for(int i=31;i>=0;i--){
		bool current_k_bit = (k>>i)&1;
		bool current_element_bit = (element>>i)&1;
		if(current_k_bit){
			if(current_element_bit){
				res += root->right_count;
				if(root->left == NULL){
					return res;
				}
				root = root->left;
			}
			else{
				res += root->left_count;
				if(root->right == NULL){
					return res;
				}
				root = root->right;
			}
		}
		else{
			if(current_element_bit){
//				res += root->right_count;
				if(root->right == NULL){
					return res;
				}
				root = root->right;
			}
			else{
//				res += root->left_count;
				if(root->left == NULL){
					return res;
				}
				root = root->left;
			}
		}
	}
	return res;
}
void insert(trienode *root, int element){
	for(int i=31;i>=0;i--){
		int x = (element>>i)&1;
		if(x){
			root->right_count++;
			if(root->right == NULL){
				root->right = new trienode();
			}
			root = root->right;
		}
		else{
			root->left_count++;
			if(root->left == NULL){
				root->left = new trienode();
			}
			root = root->left;
		}
	}
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int temp, temp1, temp2=0;
		trienode* root = new trienode();
		insert(root, 0);
		long long total = 0;
		for(int i=0;i<n;i++){
			cin>>temp;
			temp1 = temp2 ^ temp;
			total += query(root, temp1, k);
			insert(root, temp1);
			temp2 = temp1;
		}
		cout<<total<<endl;
	}
}
