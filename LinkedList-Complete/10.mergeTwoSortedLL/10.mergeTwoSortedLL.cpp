#include<iostream>
using namespace std;
/*
a = 1->3->4->7
b = 0->2->8->10->
output = 0->1->2->3->4->7->8->10->
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
node* solve(node*a, node*b){
    //merge two sorted LLs into one by rearranging the pointers using recursion
    
    //base case
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }

    //take a new head pointer
    node*c; 
    if(a->data < b->data){
        c = a;
        c->next = solve(a->next,b);
    }
    else{
        c = b;
        c->next = solve(a,b->next);
    }
    return c;
}
int main(){
    node* head1 = NULL;
    insertAtHead(head1,7);
    insertAtHead(head1,4);
    insertAtHead(head1,3);
    insertAtHead(head1,1);
    printLL(head1);// output = 1->3->4->7

    node* head2 = NULL;
    insertAtHead(head2,10);
    insertAtHead(head2,8);
    insertAtHead(head2,2);
    insertAtHead(head2,0);
    printLL(head2);//ouput = 0->2->8->10->

    node* mergedLL = solve(head1,head2);
    cout<<"Merged LL:"<<endl;
    printLL(mergedLL); //output = 0->1->2->3->4->7->8->10->
    
    return 0;
}