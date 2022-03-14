//taking linked list's data as an input from user
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
void printLL(node*head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
node* take_input1(){
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
int main(){
    node* head = take_input1(); //input = 6 5 4 3 2 1 -1
    printLL(head); // ouput = 0->1->2->3->4->5->6->
}