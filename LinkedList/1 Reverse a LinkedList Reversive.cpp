#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	struct Node* next;
	Node(int data){
		this->data = data;
		next = NULL;
	}
};
struct LinkedList{
	Node* head;
	LinkedList(){
		head = NULL;
	}
	Node* reverse(Node* head){
		if(head == NULL || head->next ==NULL){
			return head;
		}
		Node* rest = reverse(head->next);
		head->next->next = head;
		
		head->next =NULL;
		
		return rest;
		
	}
	void push(int data){
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
	void print(){
		struct Node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}
	
};

int main(){
	LinkedList ll;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		ll.push(x);
	}
	cout<<"Given Linked list"<<endl;
	ll.print();
	cout<<endll;
	ll.head = ll.reverse(ll.head);
	
	cout<<"Reversed Linked List"<<endl;
	ll.print();
	return 0;
}

