#include <bits/stdc++.h>
using namespace std;

struct node{
	char key[20];
	char mean[20];
	node *left,*right;
};

class dict{
	public:
		node *root;
		void create(){
			node *temp;
			temp=new node;
			cout<<"ENTER KEYWORD-: ";
			cin>>temp->key;
			cout<<"ENTER MEANING-: ";
			cin>>temp->mean;
			temp->left=NULL;
			temp->right=NULL;
			if(root==NULL){
				root=temp;
			}
			else{
				insert(root,temp);
			}
		}
		
		void insert(node *root,node *temp){
			if(strcmp(temp->key,root->key)<0){
				if(root->left==NULL){
					root->left=temp;
				}
				else{
					insert(root->left,temp);
				}
			}
			else{
				if(root->right==NULL){
					root->right=temp;
				}
				else{
					insert(root->right,temp);
				}
			}
		}
		
		int search(node *root,char key[20]){
			while(root!=NULL){
				if(strcmp(key,root->key)==0){
					cout<<"element found";
					return 1;
				}
				else if(strcmp(key,root->key)<0){
					root=root->left;
				}
				else{
					root=root->right;
					
				}
			}
			return -1;
		}
		
		void display(node *root){
			if(root!=NULL){
				display(root->left);
				cout<<"\nkeyword-: "<<root->key;
				cout<<"\nmeaning-: "<<root->mean;
				display(root->right);
			}
		}
		
		int update(node *root,char key[20]){
			while(root!=NULL){
				if(strcmp(key,root->key)==0){
					cout<<"ENTER NEW MEANING OF KEYWORD-: "<<root->key;
					cin>>root->mean;
					return 1;
					
				}
				if(strcmp(key,root->key)<0){
					root=root->left;
				}
				else{
					root=root->right;;
				}
			}
			return -1;
			
		}
		
		node *del(node *root,char key[20]){
			node *temp;
			if(root==NULL){
				cout<<"ELEMENT NOT FOUND";
				return root;
			}
			if(strcmp(key,root->key)<0){
				root->left=del(root->left,key);
				return root;
			}
			if (strcmp(key,root->key)>0){
				root->right=del(root->right,key);
				return root;
			}
			if (root->right==NULL && root->left==NULL){
				temp=root;
				delete temp;
				return NULL;
			}
			if(root->right==NULL){
				temp=root;
				root=root->left;
				delete temp;
				return root;
				
			}
			else if(root->left==NULL){
				temp=root;
				root=root->right;
				delete temp;
				return root;
			}
			temp=min(root->right);
			strcpy_s(root->key,temp->key);
			root->right=del(root->right,temp->key);
			return root;
		}
		
		node *min(node *q){
			while(q->left!=NULL){
				q=q->left;
			}
			return q;
		}
};



int main(){
	int choice;
	dict d;
	char om[20];
	d.root=NULL;
	bool flag=true;
	while(choice!=6){
		cout<<"\1.create\n2.display\n3.search\n4.update\n5.delete\n6.exit\n";
		cout<<"enter your choice-: ";
		cin>>choice;
		switch(choice){
			case 1:
				d.create();
				break;
			
			case 2:
				d.display(d.root);
				break;
			case 3:
				cout<<"enter word you want to search=: ";
				
				cin>>om;
				if(d.search(d.root,om)==1){
					cout<<"found";}
				else{
					cout<<"not found";
				}
				break;
			
			case 4:
				cout<<"enter word you want to update=: ";
				
				cin>>om;
				if(d.update(d.root,om)==1){
					cout<<"updated";}
				else{
					cout<<"not found";
				}
				break;
				
			case 5:
				cout<<"enter word you want to delete=: ";
				
				cin>>om;
				if(d.root==NULL){
					cout<<"\nno keyword";}
				else{
					d.root=d.del(d.root,om);
				}
				break;
			
			case 6:
				break;
				
		}
	}
}