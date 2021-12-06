#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
};

void push(Node** head_ref, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

Node* detectLoop_firstNode(Node* header){
	if(header == NULL || header->next == NULL){
		return NULL;
	}
	Node *slow_p = header,*fast_p = header;
	slow_p = slow_p->next;
	fast_p = fast_p->next->next;
	while(fast_p && fast_p->next){
		if(slow_p == fast_p){
			break;
		}
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		
	}
	
	if(slow_p!=fast_p){
		return NULL;
	}
	
	// initializing the slow pointer to head
	slow_p = header;
	while(slow_p!= fast_p){
		slow_p = slow_p->next;
		fast_p = fast_p->next;
	}
	return slow_p;
}
void printnodes( Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main(){
	Node* head = NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		push(&head, x);
	}
	head->next->next->next->next->next = head->next->next;
//	printnodes(head);
	Node* res = detectLoop_firstNode(head);
	if(res == NULL){
		cout<<" Loop not Found"<<endl;
	}
	else{
		cout<<"Loop Starting node is "<<res->data;
	}
//	printnodes(head);
}
//  https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
