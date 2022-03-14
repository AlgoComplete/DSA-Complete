#include<iostream>
using namespace std;

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
void deleteAtHead(node*&head){
    // 1 -> 2 -> 3 , head stores address of 1
	//after deltion: 2->3, head stores address of 2
    if(head == NULL){
        //nothing to delete
        return;
    }
    
    node* temp = head->next;
    //following will not delete the head bucket, but will delete the node at the address stored inside head
    delete head;
    head = temp;    
}
void deleteAtTail(node*&head){
    // 1 -> 2 -> 3 , head stores address of 1
	//after deltion: 1->2->, head will remain unchanged
    if(head == NULL){
        //nothing to delte
        return;
    }
    node*temp = head;
    node*prev = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    //1->2->3, prev will store address of 2 and temp will store address of 3
    delete temp;
    prev->next = NULL;
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
    printLL(head);// output = 1->2->3->4->5->

    deleteAtHead(head);
    printLL(head);//output = 2->3->4->5->

    deleteAtTail(head);
    printLL(head);//output = 2->3->4->

    //deletAtPosition(head,2);
    printLL(head);//output = 
    return 0;
}