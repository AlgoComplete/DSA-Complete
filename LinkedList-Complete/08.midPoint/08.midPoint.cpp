#include<iostream>
using namespace std;
/*
Brute force method - find length of ll and then traverse till len/2 to find mid point
Better approach - "Mid Point runner technique" also called fast and slow pointer technique
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
node* midPoint(node*head){
    if(head == NULL or head->next == NULL){
        //no change if there is only one node or no node at all
        return head;
    }
    node*slow = head;
    node*fast = head;
    while(fast!=NULL and fast->next != NULL){
        fast = fast->next->next; //move fast two steps
        slow = slow->next; // move slow one step
    }
    return slow;
}
int main(){
    node* head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);// output = 1->2->3->4->5->

    //odd len case- 1->2->3->4->5->
    node* midNode = midPoint(head);
    cout<<midNode->data<<endl;

    insertAtHead(head,0);
    
    //even len case - 0->1->2->3->4->5->
    midNode = midPoint(head);
    cout<<midNode->data<<endl;
    return 0;
}