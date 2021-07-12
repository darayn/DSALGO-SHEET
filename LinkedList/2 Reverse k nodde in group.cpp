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

struct node *reverse_k (struct node *head, int k)
    { 
    node* p = NULL;
    node* c = head;
    node* n;
    int count = 0;
    while(c!=NULL && count<k){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        count++;
    }
        
    if(n!=NULL){
        head->next = reverse_k(n,k);
    }
    return p;
}


void printnodes(struct node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	struct node *head = NULL;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		push(&head, x);
	}
	cout<<"List Before Reversing in group"<<endl;
	printnodes(head);
	cout<<endl;
	head = reverse_k(head,k);
	cout<<"List After Reversing in group"<<endl;
	printnodes(head);
}
