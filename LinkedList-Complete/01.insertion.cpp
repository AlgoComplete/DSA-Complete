#include<iostream>
using namespace std;

/*
            100        200         300         400
h = 100    1 200      2 300       3 400      4 NULL
*/
//above is an example of lined list, where there are 5 nodes and head points to first node with address 100

//create a node class 
class node{
public:
    int data; // for storing integer data into our nodes
    node* next; // variable - 'next'is pointer to node datatype
    
    node(int d){
        //constructor
        data = d;
        next = NULL; //in any new node 'next' will point to 'NULL' in the begining.
    }
};

void insertAtHead(node* &head, int d){
    //head's datatype is node* and it is passed by reference, therefore node*&head
    if(head == NULL){
        //first node insertion
        head = new node(d);
        return;
    }
    //insertion for remaining nodes
    node* temp = new node(d); //create a temp node
    temp->next = head; //temp's next will store the address stored in head
    head = temp; // head will point to new node i.e. temp
}

void insertAtTail(node*&head, int d){
   if(head == NULL) {
       //empty ll
       head = new node(d);
       return;
   }
   //traverse the linked list and get the tail pointer 
   node* tail = head;
   while(tail->next != NULL){
       tail = tail->next;
   }
   //now tail is pointing to the current last node in the LL.
   node *temp = new node(d); //temp node
   tail->next = temp;
}
//will return length of the LL
int length(node*head){
	int cnt = 0;
	while(head!=NULL){
		cnt++;
		head = (*head).next;
		//or head = head->next;
	}
	return cnt;
}

//p -> position at which node is to be inserted
// p = 0 - means, we are inserting from head
//for LL= 0 -> 1 -> 2 -> 4, if p = 2, d = 3
//new LL will be : 0>1>3>2>4
//p>len of ll, insertion at tail
void insertionAtPosition(node*&head, int d, int p){
    if(head == NULL or p == 0){
		insertAtHead(head,d);
		return;
	}
	else if(p>=length(head)){
		//insert at tail
		insertAtTail(head,d);
		return;
	}
	else{
		//insert in the middle
		//reach temp node by taking p-1 jumps
		int jump = 1;
		node*temp = head;
		while(jump<=p-1){
			temp = temp->next;
			jump++;
		}
		//create a new node
		node*n = new node(d);
		n->next = temp->next;
		temp->next = n;

	}
}
void printLL(node*head){
    //traversing the linked list
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next; //updating head
    }
    cout<<endl;
}
int main(){
    
    node* head = NULL; //initialising empty linked list

    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    printLL(head); //output = 1->2->3->4->5->

    insertAtTail(head,6);
    insertAtTail(head,7);
    printLL(head); // output = 1->2->3->4->5->6->7->

    insertionAtPosition(head,0,0);
    printLL(head); // ouput = 0->1->2->3->4->5->6->7->

    cout<<length(head)<<endl; //output = 8
    
    insertionAtPosition(head,8,8);
    printLL(head); //output = 0->1->2->3->4->5->6->7->8->

    //now len of LL = 9
    insertionAtPosition(head,9,20); // will result into insertionAtTail
    printLL(head);// output = 0->1->2->3->4->5->6->7->8->9->

    //inserting 45 between 4->5
    insertionAtPosition(head,45,5);
    printLL(head); //output = 0->1->2->3->4->45->5->6->7->8->9->

    return 0;
}