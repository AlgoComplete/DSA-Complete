#include<iostream>
using namespace std;
/*
LL = head -> 1 -> 2 -> 3 -> 4
after reversal
LL = 1 <- 2 <- 3 <- 4 <- head

iterative appr - o(n) time + o(1) space

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
void reverseLL(node*&head){
    if(head == NULL or head->next == NULL){
        //no node or just one node
        return;
    }
    //we will do this using previous, current and next pointers
    node* prev = NULL;
    node* curr = head;
    node* next;
    while(curr != NULL){
        next = curr->next;

        curr->next = prev; // make the current node point to previous node

        //update the prev and curr pointers
        prev = curr;
        curr = next;
    }
    head = prev;
}
int main(){
    node* head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);// output = 1->2->3->4->5->

    reverseLL(head);
    printLL(head);//output = 5->4->3->2->1->
    return 0;
}