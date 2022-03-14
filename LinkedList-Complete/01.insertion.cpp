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
    return 0;
}