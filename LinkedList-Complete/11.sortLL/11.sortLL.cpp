#include<iostream>
using namespace std;
/*
sort the given LL using merge sort:
1. Divide into two using mid point runner technique.
2. Recursively sort two Linked Lists
3. Merge them
T(n) = O(NLogN)

*/
class node{
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};
void insertAtHead(node*&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}
void printLL(node*head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
node* take_input(){
    //will take input from cin unless -1 is encountered
    node* head = NULL;
    int d;
    cin>>d;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}
ostream& operator<<(ostream &os, node* head){
	printLL(head);
	return os; //cout object returned
}
istream& operator>>(istream &is, node*&head){
	head = take_input();
	return is;
}
node* merge(node* a, node* b){
	
	//base case
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}

	//take a new head pointer
	node*c;
	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c -> next = merge(a,b->next);
	}

	return c;
}

node* midPoint(node* head){
	
	if(head == NULL or head->next == NULL){
		return head;
	}

	node*slow = head;
	node*fast = head->next;

	while(fast !=NULL and fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* mergeSort(node* head){

	//base case - ll with 0 or 1 node
	if(head == NULL or head->next == NULL){
		return head;
	}

	//rec case
	//1 - Divide
	node*mid = midPoint(head);
	node*a = head;
	node*b = mid->next;

	mid->next = NULL;

	//2. rec sorting a and b
	a = mergeSort(a);
	b = mergeSort(b);

	//3. merge them
	node*c = merge(a,b);
	return c;
}
int main(){
    node* head; 
    cin>>head;
    cout<<head;

    cout<<"After sorting:"<<endl;
    head = mergeSort(head);
    cout<<head;
    return 0;
}