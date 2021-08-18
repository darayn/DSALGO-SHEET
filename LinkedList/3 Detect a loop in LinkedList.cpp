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
int detectLoop_using_floyd_cycle(Node* header){
	Node *slow_p = header,*fast_p = header;
	while(slow_p && fast_p && fast_p->next){
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if(slow_p == fast_p){
			return 1;
		}
	}
	return 0;
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
//	head->next->next->next->next = head;
	if(detectLoop_using_floyd_cycle(head)){
		cout<<" Loop Found"<<endl;
	}
	else{
		cout<<"No Loop"<<endl;
	}
//	printnodes(head);
}


//https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/  - for other methods
