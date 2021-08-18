#include<bits/stdc++.h>
using namespace std;;

#define MAX 256
#define MAX_WORD_LEN 500

struct trieNode{
	struct trieNode *child[MAX];
	int freq;
};

struct trieNode *newTrieNode(){
	struct trieNode *newNode = new trieNode;
	newNode->freq = 1;
	for(int i=0;i<MAX;i++){
		newNode->child[i] = NULL;
	}
	return newNode;
}

void insert(struct trieNode *root, string str){
	int len = str.length();
	struct trieNode *pCrawl = root;
	
	for(int level = 0;level<len;level++){
		int index = str[level];
		
		if(!pCrawl->child[index]){
			pCrawl->child[index] = newTrieNode();
		}
		else{
			(pCrawl->child[index]->freq)++;
		}
		pCrawl = pCrawl->child[index];
	}
}

void findPrefixesUtil(struct trieNode *root, char prefix[], int ind){
	if(root==NULL){
		return;
	}
	if(root->freq == 1){
		prefix[ind] = '\0';
		cout<<prefix<< " ";
		return;
	}
	
	for(int i=0;i<MAX;i++){
		if(root->child[i] != NULL){
			prefix[ind] = i;
			findPrefixesUtil(root->child[i], prefix, ind+1);
		}
	}
}

void findPrefixes(string arr[], int n){
	struct trieNode *root = newTrieNode();
	root->freq = 0;
	for(int i=0;i<n;i++){
		insert(root,arr[i]);
	}
	char prefix[MAX_WORD_LEN];
	
	findPrefixesUtil(root, prefix, 0);
}


int main(){
	int n;
	cin>>n;
	string arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	findPrefixes(arr, n);
}
