#include<iostream>
using namespace std;
/*
A doubly linked list stores the address of preceeding node as well as the next node
*/
class node{
public:
	int data;
	node* next;
	node* prev;
	node(int d){
		data = d;
		next = NULL;
		prev = NULL;
	}
};

void insertAtHead(node*&head, node*&tail,int d){
	//inserting 1st node
	if(head == NULL){
		head =  new node(d);
		tail = head;
		return;
	}

	//inserting remaining nodes
	node *n = new node(d);
	n -> next = head;
	head->prev = n;
	head = n;
	head->prev = NULL;	

}
void printLL(node*head){
	while(head!=NULL){
		cout<<head->data<<"<->";
		head = head->next;
	}

	cout<<endl;
}

int main(){
	
	node*head = NULL;
	node*tail = NULL;
	insertAtHead(head,tail,1);
	insertAtHead(head,tail,2);
	insertAtHead(head,tail,3);

	printLL(head);

	node*temp = tail;
	while(temp!= NULL){
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
	return 0;
}
