#include<bits/stdc++.h>
#include<string>
using namespace std;
struct node{
	int key;
	struct node *left, *right;
};
void inorder(struct node * root){
	if(root!=NULL){
		inorder(root->left);
	
		cout<<root->key<<" -> ";
	
		inorder(root->right);
	}
}
struct node *newNode(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key =item;
	temp->left = temp->right = NULL;
	return temp;
}
struct node* insert(struct node *node, int key){
	if(node == NULL){
		return newNode(key);
	}
	if(key < node->key){
		node->left = insert(node->left,key);
	}
	else{
		node->right = insert(node->right, key);
	}
	return node;
	
}
struct node* search(struct node* root, int key)
{
   
    if (root == NULL || root->key == key){
    	return root;
	}
    if (root->key < key){
    	return search(root->right, key);
	}
    return search(root->left, key);
}
struct node* minValueNode(struct node* node){
    struct node* current = node;
    while(current && current->left!=NULL){
        current = current->left;
    }
    return current;
}
struct node* deleteNode(struct node* root, int key) {
    if(root == NULL){
        return root;
    }
    if(key< root->key){
        root->left = deleteNode(root->left, key);
    }
    else if(key> root->key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->left == NULL){
            struct node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node* temp = root->left;
            delete(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int main(){
	struct node *root =NULL;
	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 14);
	root = insert(root, 4);
	cout << "Inorder traversal: ";
  	inorder(root);
  	cout<<endl;
  	if(deleteNode(root, 10)!=NULL){
  		cout<<"Deleted";
	}
	else{
		cout<<"Not Deleted";
	}
  	inorder(root);
	
}
