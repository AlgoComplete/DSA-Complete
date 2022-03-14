#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*next;

	node(int d){
		data = d;
		next = NULL;
	}
};

void insertAtHead(node*&head, int data){

	node* n = new node(data);
	node*temp = head;

	n->next = head;

	if(temp!=NULL){
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = n;
	}
	else{
		//first node
		n->next = n; //self loop
	}
	head = n;
}

node* getnode(node*head, int data){
	
	node*temp = head;
	//checking for all nodes except last node
	while(temp->next != head){
		if(temp->data == data){
			return temp;
		}
		temp = temp->next;
	}
	//checking for last node
	if(temp->data == data){return temp;}
	return NULL;
}

void deletion(node*&head, int data){
	
	node*del = getnode(head,data);
	if(del == NULL){
		return;
	}

	//if head is the node to be deleted
	if(del == head){
		head = head->next;	
	}
	//otherwise
	node* temp = head;
	//stop one step behind the node to be deleted
	while(temp->next != del){
		temp = temp->next;
	}
	temp->next = del->next;
	delete del;
}

void printCircularLL(node*head){
	node*temp = head;
	while(temp->next != head){
		cout<<temp->data<<"->";
		temp= temp->next;
	}
	cout<<temp->data<<endl;
	return;
}

int main(){

	node*head = NULL;
	insertAtHead(head,1);
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtHead(head,4);
	printCircularLL(head);
	deletion(head,2);
	printCircularLL(head);
	deletion(head,4);
	printCircularLL(head);
	return 0;
}
