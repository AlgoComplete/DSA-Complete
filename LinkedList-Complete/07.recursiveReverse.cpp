#include<iostream>
using namespace std;
/*
LL = head -> 1 -> 2 -> 3 -> 4
after reversal
LL = 1 <- 2 <- 3 <- 4 <- head

iterative appr - o(n) time + o(1) space
recursive appr - o(n) time + o(n) stack space
iterative appr is more efficient

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
node* recReverseLL(node* head){
    //base case - smallest ll that we need to reverse
    if(head->next == NULL or head == NULL){
        return head; //this itself is reversed ll
    }

    //rec case
    node* smallHead = recReverseLL(head->next);
    // 1 -> 2 <- 3 <-4 <- 5
    //we will assume that our work is done by recuresion and we get above like conf. with smallHead pointing to 5

    node*temp = head->next;
    temp->next = head;
    head->next = NULL;

    return smallHead;

}
int main(){
    node* head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);// output = 1->2->3->4->5->

    head = recReverseLL(head);
    printLL(head);//output = 5->4->3->2->1->
    return 0;
}