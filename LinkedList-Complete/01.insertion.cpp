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
    if(head == NULL){
        //first node insertion
        head = new node(d);
        return;
    }
    //insertion for remaining nodes
    node* n = new node(d);
    n->next = head;
    head = n;
}
void printLL(node*head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    
    node* head = NULL;
    
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    printLL(head);
    return 0;
}