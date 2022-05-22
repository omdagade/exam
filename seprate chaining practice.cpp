#include <iostream>
using namespace std;

struct node{
	long long int telephone;
	node *next;
};

class sepratechaining{
	public:
	node *ht[10];
	sepratechaining(){
		for(int i=0;i<10;i++){
			ht[i]=NULL;
			
		}
	}
	
	void insert(long long int key){
		int a=key%10;
		node *p=new node;
		p->telephone=key;
		p->next=NULL;
		if(ht[a]==NULL){
			ht[a]=p;
		}
		else{
			node *q=ht[a];
			while(q->next!=NULL){
				q=q->next;
			}
			q->next=p;
			
		}
	}
	
	void display(){
		for(int i=0;i<10;i++){
			node *p;
			p=ht[i];
			if(p==NULL){
				cout<<i<<"\t-\n";
			}
			else{
				while(p!=NULL){
				
				cout<<i<<"\t"<<p->telephone;
				p=p->next;
			}
				cout<<"\n";
			}
			
		}
	}
	
	void search(long long int key){
		int loc=key%10;
		int com=0;
		int flag=0;
		node *p=ht[loc];
		while(p->telephone!=key){
			com=com+1;
			p=p->next;
		}
		cout<<"element found at- "<<p<<" address in "<<com+1<<" comparisons\n";
}
	
};

int main(){
	sepratechaining h;
	long long int choice,v;
	while(choice!=4){
	
		cout<<"1.insert\n2.display\n3.search\n4.exit\n";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"element to insert-: ";
				cin>>v;
				h.insert(v);
				break;
			
			case 2:
				h.display();
				break;
			case 3:
				cout<<"element to search: ";
				cin>>v;
				h.search(v);
				break;
			case 4:
				break;
			
			default:
				cout<<"wrong input";
				
		}
	}
	return 0;
}




















