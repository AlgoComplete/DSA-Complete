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
//taking input directly from an existing text file like input.txt
//run through cmd or terminal
//g++ inputLL.cpp -o a
//a < input.txt
node* take_input2(){
    int d;
    node*head = NULL;
    while(cin>>d){
        insertAtHead(head,d);
    }
    return head;
}
int main(){
    
    //node* head1 = take_input2(); //input file contains 1 2 3 4 78 98
    //printLL(head1); // output = 98->78->4->3->2->1->

    node* head2 = take_input1(); //input = 6 5 4 3 2 1 -1
    printLL(head2); // ouput = 0->1->2->3->4->5->6->
}