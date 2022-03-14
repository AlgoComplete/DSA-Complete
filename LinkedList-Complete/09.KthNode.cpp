#include<iostream>
using namespace std;
/*
kth node from end 
1 -> 2 -> 3 -> 4

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
node* kthNode(node*head,int k){
    //assuming that kth node exists
    //we will maintain fast and slow pointers
    //Take fast pointer k steps ahead and then move both pointers one step
    node*slow = head;
    node*fast = head;
    int cnt = 0;
    while(cnt<k){
        //k jumps for fast pointer
        fast = fast->next;
        cnt++;
    }
    while(fast!= NULL){
        //move both one step at a time
        fast = fast->next;
        slow = slow->next;
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

    node* k_node = kthNode(head,1);
    cout<<k_node->data<<endl;

    k_node = kthNode(head,4);
    cout<<k_node->data<<endl;
    return 0;
}