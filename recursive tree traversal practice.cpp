#include <iostream>
using namespace std;

struct node{
	int data;
	node *left,*right;
};

class tree{
	public:
		node *create(){
			int a;
			cout<<"ENTER VALUE-: ";
			cin>>a;
			node *p=new node;
			p->data=a;
			if(a==-1){
				return NULL;
			}
			cout<<"ENTER LEFT CHILD OF "<<a<<" : ";
			p->left=create();
			cout<<"ENTER RIGHT CHILD OF "<<a<<" : ";
			p->right=create();
			return p;
		}
		
		void preorder(node *root){
			if(root!=NULL){
				cout<<root->data;
				preorder(root->left);
				preorder(root->right);
			}
		}
		
		void postorder(node *root){
			if(root!=NULL){
				
				postorder(root->left);
				postorder(root->right);
				cout<<root->data;
			}
		}
		
		void inorder(node *root){
			if(root!=NULL){
				
				inorder(root->left);
				cout<<root->data;
				inorder(root->right);
				
			}
		}
};

int main(){
	tree t;
	node *root;
	root=t.create();
	cout<<"\nPreorder Traversal-: ";
	t.preorder(root);
	cout<<"\nPostorder Traversal-: ";
	t.postorder(root);
	cout<<"\nInorder Traversal-: ";
	t.inorder(root);
	return 0;
}

















