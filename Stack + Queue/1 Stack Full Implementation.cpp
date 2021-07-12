#include<bits/stdc++.h>
using namespace std;

class Stack{
	public:
		int data;
		Stack* next;
};

Stack* newNode(int data){
	Stack* Node = new Stack();
	Node->data = data;
	Node->next = NULL;
	return Node;
}

int isEmpty(Stack* root){
	return !root;
}

void push(Stack** root, int data){
	Stack* Node = newNode(data);
	Node->next = *root;
	*root = Node;
	cout<<data<<" pushed to stack\n";
}

int pop(Stack** root){
	if(isEmpty(*root)){
		return INT_MIN;
	}
	Stack* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}

int peek(Stack* root){
	if(isEmpty(root)){
		return INT_MIN;
	}
	return root->data;
}

int main(){
	Stack* root = NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		push(&root, x);
	}
	
	cout<<pop(&root)<< " popped from stack\n";
	cout<<"Top element is "<< peek(root)<<endl;
	
	cout<<"Elements present in stack : ";
	
	while(!isEmpty(root)){
		cout<<peek(root)<<" ";
		pop(&root);
	}
	return 0;
	
}







