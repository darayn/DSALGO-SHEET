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
void removeLoop(Node* loop_node, Node* head){
	Node *ptr1;
	Node *ptr2;
	
	ptr1 = head;
	while(1){
		ptr2 = loop_node;
		while(ptr2->next != loop_node && ptr2->next != ptr1){
			ptr2 = ptr2->next;
		}
		if(ptr2->next == ptr1){
			break;
		}
		
		ptr1 = ptr1->next;
	}
	ptr2->next = NULL;
}

int detectLoop_using_floyd_cycle(Node* header){
	Node *slow_p = header,*fast_p = header;
	while(slow_p && fast_p && fast_p->next){
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if(slow_p == fast_p){
			removeLoop(slow_p, header);
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
//	head->next->next->next->next->next = head->next->next;
//	printnodes(head);
	if(detectLoop_using_floyd_cycle(head)){
		cout<<" Loop Found"<<endl;
	}
	else{
		cout<<"No Loop"<<endl;
	}
	printnodes(head);
}

//https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
