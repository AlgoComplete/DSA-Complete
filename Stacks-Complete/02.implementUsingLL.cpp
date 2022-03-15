//implementation of stack class using linked list
/*
Functionalities in stack class:
    1. Insertion(push)
    2. pop
    3. Top - will give the top most element of stack
    4. isEmpty() - will check if the stack is empty or not
*/
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int d)    {
        data = d;
        next = NULL;
    }
};
void insertAtHead(node*&head,int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
}
void deletAtHead(node*&head){
	if(head == NULL){
		return;
	}
	node*tmp = head->next;
	delete head;
	head = tmp;
}
class Stack{
private:
    node* head = NULL;
public:
    void push(int d){
        insertAtHead(head,d);
    }
    bool isEmpty(){
        if(head == NULL)    return true;
        else    return false;
    }
    void pop(){
        if(!isEmpty()){
            deletAtHead(head);
        }
    }
    int top(){
        return head->data;
    }
};
int main()
{
    Stack s;
    for(int i = 1; i<=5; i++){
        s.push(i);
    }
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}