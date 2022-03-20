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

void insertAtTail(int d, pair<node*,node*> &ll){
    if(ll.first == NULL or ll.second == NULL){
        //inserting first node;
        ll.second = new node(d);
        ll.first = ll.second; // in the begining head == tail
        return;
    }
    //inserting remaining nodes
    node* n = new node(d);
    ll.second->next = n;
    ll.second = n;

}
void deleteAtHead(node*&head){
    //no need to check for empty .. will be check in Queue class itself
    
    node* temp = head->next;
    //following will not delete the head bucket, but will delete the node at the address stored inside head
    delete head;
    head = temp;  
}
class Queue{
    int cs;
    pair<node*,node*> ll; // we will stor both head,tail pointers, ll.first is head and ll.second is tail

public:
    Queue(){
        cs = 0;
    }
    bool isEmpty(){
        return cs == 0;
    }
    void push(int data){
        insertAtTail(data,ll);
        cs++;
    }
    void pop(){
        if(!isEmpty()){
            deleteAtHead(ll.first);
            cs--;
        }
    }
    int getFront(){
        return ll.first->data;
    }
};

int main()
{
    Queue q;
    for(int i = 1;i<=6; i++){
        q.push(i);
    }
    q.pop();
    q.pop();

    q.push(7);
    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}