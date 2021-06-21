#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};

void push(struct node **head_ref, int data){
	struct node *node;
	node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->next = (*head_ref);
	(*head_ref) = node;
	
}

void reverse(struct node **head_ref){
	struct node *temp = NULL;
	struct node *prev = NULL;
	struct node *current = (*head_ref);
	while(current!=NULL){
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	(*head_ref) = prev;
}

void printnodes(struct node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main(){
	int n;
	cin>>n;
	struct node *head = NULL;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		push(&head, x);
	}
	cout<<"List Before Reversing"<<endl;
	printnodes(head);
	cout<<endl;
	reverse(&head);
	cout<<"List After Reversing"<<endl;
	printnodes(head);
}
