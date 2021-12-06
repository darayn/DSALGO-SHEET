#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}

Node *removeDuplicates(Node *head)
{
    Node *cur = head;
    Node *next_next;
    if(cur == NULL){
        return head;
    }
    while(cur->next != NULL){
        if(cur->data == cur->next->data){
            next_next = cur->next->next;
            free(cur->next);
            cur->next = next_next;
        }
        else{
            cur = cur->next;
        }
    }
    return head;
}
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}


