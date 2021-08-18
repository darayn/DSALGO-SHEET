#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
};


struct TrieNode *getNode(void){
	struct TrieNode *pNode = new TrieNode;
	pNode->isEndOfWord = false;
	for(int i=0;i<ALPHABET_SIZE;i++){
		pNode->children[i] = NULL;
	}
	return pNode;
}

void insert(struct TrieNode *root, string key){
	struct TrieNode *pCrwal = root;
	for(int i=0;i<key.length();i++){
		int index = key[i] - 'a';
		if(!pCrwal->children[index]){
			pCrwal->children[index] = getNode();
		}
		pCrwal = pCrwal->children[index];
	}
	pCrwal->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key){
	struct TrieNode *pCrawl = root;
	for(int i=0;i<key.length();i++){
		int index = key[i] - 'a';
		if(!pCrawl->children[index]){
			return false;
		}
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl!=NULL && pCrawl->isEndOfWord);
}

bool wordBreak(string str, TrieNode *root){
	int size = str.size();
	
	if(size == 0){
		return true;
	}
	for(int i=1;i<=size;i++){
		if(search(root, str.substr(0,i))&& wordBreak(str.substr(i,size-i), root)){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	string dictionary[n];
	for(int i=0;i<n;i++){
		cin>>dictionary[i];
	} 
	struct TrieNode *root = getNode();
	
	for(int i=0;i<n;i++){
		insert(root, dictionary[i]);
	}
	
	int queries;
	cin>>queries;
	for(int i=0;i<queries;i++){
		string q;
		cin>>q;
		if(wordBreak(q, root)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
}
